#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int p, k;

bool used[1000005] = {};

int main() {
    scanf("%d%d", &p, &k);
    if (k == 0) {
        int ans = 1;
        REP(i, p - 1) ans = (LL)ans * p % MOD;
        printf("%d\n", ans);
        return 0;
    }
    if (k == 1) {
        int ans = 1;
        REP(i, p) ans = (LL)ans * p % MOD;
        printf("%d\n", ans);
        return 0;
    }
    int ans = 1;
    for (int i = 1; i < p; ++i) if (!used[i]) {
        for (int j = i; !used[j]; j = (LL)j * k % p) {
            used[j] = true;
        }
        ans = (LL)ans * p % MOD;
    }
    printf("%d\n", ans);
    return 0;
}