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

const int maxn = 1000 * 1000 + 100;
const int maxlog = 21;

int n, m;
int mindiv[maxn];
long long precalc[maxlog];
bool used[maxn];

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }

    return gcd(y, x % y);
}

vector <pair <int, int> > getfactors(int x) {
    vector <pair <int, int> > factors;
    int lst = -1;
    while (x > 1) {
        int curdiv = mindiv[x];
        if (curdiv != lst) {
            factors.pb(mp(curdiv, 0));
        }        
        lst = curdiv;
        factors[(int) factors.size() - 1].sc++;
        
        x /= curdiv;
    }

    return factors;
}

void buildprecalc(int m) {
    precalc[0] = 0ll;
    for (int i = 1; i < maxlog; i++) {
        precalc[i] = precalc[i - 1] + m;

        for (int j = 0; j <= m; j++) {
            used[j] = false;
        }
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= m; k++) {
                if (j * k % i == 0 && !used[j * k / i]) {
                    used[j * k / i] = true;
                    precalc[i]--;                    
                }
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i < maxn; i++) {
        mindiv[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (mindiv[i] == i) {
            for (int j = 2; i * j < maxn; j++) {
                mindiv[i * j] = min(mindiv[i * j], i);
            }
        }
    }

    buildprecalc(m);

    long long ans = 1ll;
    for (int i = n; i >= 2; i--) {
        vector <pair <int, int> > factors = getfactors(i);
        
        int d = 0;
        for (int j = 0; j < (int) factors.size(); j++) {
            d = gcd(d, factors[j].sc);
        }

        if (d != 1) {
            continue;
        }

        long long cur = i;
        int len = 0;
        while (cur <= n) {
            len++;
            cur *= i;
        }

        ans += precalc[len];
    }

    printf("%lld\n", ans);

    return 0;
}