#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int c[505];
bitset<505> can[505];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", c + i);
    can[0].set(0);
    REP(i, n) {
        for (int j = k - c[i]; j >= 0; --j) {
            can[j + c[i]] |= (can[j] << c[i]) | can[j];
        }
    }
    int tot = 0;
    REP(i, k + 1) if (can[k].test(i)) ++tot;
    printf("%d\n", tot);
    REP(i, k + 1) if (can[k].test(i)) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}