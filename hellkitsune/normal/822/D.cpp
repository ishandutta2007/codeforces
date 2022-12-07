#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int t, l, r;

int d[5000002];
int di[5000001];

int main() {
    memset(di, -1, sizeof di);
    for (int i = 2; i < 10000; ++i) if (di[i] == -1) {
        for (int j = 2 * i; j <= 5000000; j += i) {
            if (di[j] == -1) {
                di[j] = i;
            }
        }
    }
    d[0] = d[1] = 0;
    for (int i = 2; i <= 5000000; ++i) {
        if (di[i] == -1) di[i] = i;
        d[i] = ((LL)i * (di[i] - 1) / 2 + d[i / di[i]]) % MOD;
    }
    scanf("%d%d%d", &t, &l, &r);
    int mul = 1;
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans = (ans + (LL)mul * d[i]) % MOD;
        mul = (LL)mul * t % MOD;
    }
    cout << ans << endl;
    return 0;
}