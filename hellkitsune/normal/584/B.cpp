#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, ans = 1;
const int MOD = 1e9 + 7;

int main() {
    scanf("%d", &n);
    REP(i, 3 * n) ans = 3ll * ans % MOD;
    int sub = 1;
    REP(i, n) sub = 7ll * sub % MOD;
    ans = (ans - sub + MOD) % MOD;
    printf("%d\n", ans);
    return 0;
}