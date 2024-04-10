#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];
int ans[200000];
int used[200000] = {};
int tot = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    int x = -1;
    REP(i, n) if (a[i] == i) {
        x = i;
        used[x] = 1;
        break;
    }
    REP(i, n) ans[i] = a[i];
    int cur = 2;
    REP(i, n) if (!used[i]) {
        int j;
        for (j = i; !used[j]; j = a[j]) {
            used[j] = cur;
        }
        if (used[j] == cur) {
            ++tot;
            if (x == -1) {
                x = j;
                ans[x] = x;
            } else {
                ans[j] = x;
            }
        }
        ++cur;
    }
    printf("%d\n", tot);
    REP(i, n) printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}