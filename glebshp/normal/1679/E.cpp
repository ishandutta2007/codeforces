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

const int mdl = 998244353;
const int maxn = 1010;
const int alph = 17;

int n, q;
char str[maxn];
char charset[maxn];
int ans[alph + 1][1 << alph];
int pwrs[alph + 1][maxn];
int gcnt = 0;

void precalc() {
    for (int i = 1; i <= alph; i++) {
        pwrs[i][0] = 1;
        for (int j = 1; j < maxn; j++) {
            pwrs[i][j] = (pwrs[i][j - 1] * 1ll * i) % mdl;
        }
    } 
}

void doConvolutions() {
    for (int i = 1; i <= alph; i++) {
        for (int j = 0; j < alph; j++) {
            for (int k = 0; k < (1 << alph); k++) {
                if (((k >> j) & 1) == 0) {
                    ans[i][k + (1 << j)] += ans[i][k];
                    if (ans[i][k + (1 << j)] >= mdl) {
                        ans[i][k + (1 << j)] -= mdl;
                    }
                }
            }
        }
    }
}

void process() {
    precalc();

    for (int i = 0; i < n; i++) {
        gcnt += (str[i] == '?');
    }

    for (int i = 0; i < n; i++) {
        for (int t = 0; t < 2; t++) {
            int mask = 0;
            int lb = i;
            int rb = i + t;
            int pwr = 0;
            int pwrout = gcnt;
            while (lb >= 0 && rb <= n - 1) {
                if (str[lb] == '?') {
                    pwrout--;
                }
                if (lb != rb && str[rb] == '?') {
                    pwrout--;
                }
                int cnt = (str[lb] == '?') + (str[rb] == '?');
                if (cnt == 0) {
                    if (str[lb] != str[rb]) {
                        break;
                    }
                } else if (cnt == 1) {
                    if (str[lb] != '?') {
                        mask |= (1 << int(str[lb] - 'a'));
                    } else {
                        mask |= (1 << int(str[rb] - 'a'));
                    }
                } else {
                    pwr++;    
                }

                for (int j = 1; j <= alph; j++) {
//                    if (j == 2) {
//                        cerr << j << ' ' << lb << ' ' << rb << ' ' << pwrs[j][pwr + pwrout] << endl;
//                    }
                    ans[j][mask] += pwrs[j][pwr + pwrout];
                    if (ans[j][mask] >= mdl) {
                        ans[j][mask] -= mdl;
                    }
                }

                lb--;
                rb++;
            }
        }
    }    

    doConvolutions();
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    scanf("%s", str);
    process();

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s", charset);
        int sz = strlen(charset);
        int mask = 0;
        for (int j = 0; j < sz; j++) {
            mask += (1 << int(charset[j] - 'a'));
        }
        printf("%d\n", ans[sz][mask]);
    }

    return 0;
}