#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;
const int maxc = 1000 * 1000 + 100;
const int maxlog = 14;

int n;
int a[maxn];
int mindiv[maxc];
int maskvalue[1 << maxlog];
vector <pair <int, int> > primes[maxc];
int inans[maxc];

int popcount(int x) {
    int c = 0;
    while (x > 0) {
        c += x & 1;
        x /= 2;
    }

    return c;
}

void precalc() {
    for (int i = 1; i < maxc; i++) {
        mindiv[i] = i;
    }
    for (int i = 2; i < maxc; i++) {
        if (mindiv[i] == i) {
            for (int j = 2; j * i < maxc; j++) {
                mindiv[i * j] = min(mindiv[i * j], i);
            }
        }
    }
    for (int i = 0; i < (1 << maxlog); i++) {
        int pc = popcount(i);
        if (pc % 2 == 1) {
            maskvalue[i] = -pc + 2;
        } else {
            maskvalue[i] = pc - 2;
        }
    }
}

vector <pair <int, int> > getfactors(int x) {
    vector <pair <int, int> > result;

    int lst = -1;
    while (x > 1) {
        int curdiv = mindiv[x];
        if (curdiv != lst) {
            result.pb(mp(curdiv, 0));
        }
        lst = curdiv;
        result[(int) result.size() - 1].sc++;
        x /= curdiv;
    }

    return result;
}

vector <int> selectSubset() {
    for (int i = 0; i < n; i++) {
        vector <pair <int, int> > factors = getfactors(a[i]);
        for (int j = 0; j < (int) factors.size(); j++) {
            primes[factors[j].fs].pb(mp(factors[j].sc, i));
        }    
    }

    set <int> subset;
    for (int i = 2; i < maxc; i++) {
        if (mindiv[i] == i) {
            int m = primes[i].size();
            sort(primes[i].begin(), primes[i].end());
            if (m == n) {
                subset.insert(primes[i][0].sc);
                subset.insert(primes[i][1].sc);    
                inans[i] = 2;
            }
            if (m == n - 1) {
                subset.insert(primes[i][0].sc);
                inans[i] = 1;
            }            
        }    
    }

    for (int i = 2; i < maxc; i++) {
        if (inans[i] == 0) {
            int cnt = 0;
            for (int ind : subset) {
                cnt += int(a[ind] % i != 0);
            }

            if (cnt < 2) {
                for (int j = 0; j < n; j++) {
                    if (subset.find(j) == subset.end() && (a[j] % i != 0)) {
                        subset.insert(j);
                        cnt++;        
                    }
                    if (cnt == 2) {
                        break;
                    }
                }
            }
        }
        if (inans[i] == 1) {
            int cnt = 0;
            for (int ind : subset) {
                cnt += int(a[ind] % i != 0);
            }

            if (cnt < 1) {
                for (int j = 0; j < n; j++) {
                    if (subset.find(j) == subset.end() && (a[j] % i != 0)) {
                        subset.insert(j);
                        cnt++;        
                    }
                    if (cnt == 1) {
                        break;
                    }
                }
            }
        }
    }

    return vector <int>(subset.begin(), subset.end());
}

vector <pair <int, vector <int> > > constructAnswer(vector <int> subset) {
    int m = (int) subset.size();

    vector <pair <int, vector <int> > > ans;
    for (int i = 1; i < (1 << m); i++) {
        vector <int> tmp;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                tmp.pb(subset[j]);
            }
        }

        for (int j = 0; j < abs(maskvalue[i]); j++) {
            ans.pb(mp(int(maskvalue[i] < 0), tmp));
        }
    }

    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    precalc();
    vector <int> subset = selectSubset();
    vector <pair <int, vector <int> > > ans = constructAnswer(subset);

    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%d %d", ans[i].fs, (int) ans[i].sc.size());
        for (int j = 0; j < (int) ans[i].sc.size(); j++) {
            printf(" %d", ans[i].sc[j] + 1);
        }
        printf("\n");
    }

    return 0;
}