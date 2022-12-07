#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
map<int, int> x, y;
map<PII, int> all;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int a, b;
        scanf("%d%d", &a, &b);
        ++x[a];
        ++y[b];
        ++all[mp(a, b)];
    }
    LL ans = 0;
    for (auto z : x) ans += (LL)z.second * (z.second - 1) / 2;
    for (auto z : y) ans += (LL)z.second * (z.second - 1) / 2;
    for (auto z : all) ans -= (LL)z.second * (z.second - 1) / 2;
    cout << ans << endl;
    return 0;
}