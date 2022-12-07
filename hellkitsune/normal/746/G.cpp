#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, t, k;
int a[200005];
int beg[200005], ed[200005];
int par[200005];

int main() {
    scanf("%d%d%d", &n, &t, &k);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", a + i);
    }
    a[0] = 1;
    beg[0] = 0;
    beg[1] = 1;
    ed[1] = 1 + a[1];
    for (int i = 2; i <= t; ++i) {
        beg[i] = beg[i - 1] + a[i - 1];
        ed[i] = beg[i] + a[i];
    }
    for (int i = 1; i <= t; ++i) {
        for (int j = beg[i]; j < ed[i]; ++j) {
            par[j] = beg[i - 1];
        }
    }
    int cur = n - t;
    if (cur < k) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 2; i <= t; ++i) {
        for (int jj = beg[i - 1] + 1, kk = beg[i] + 1; jj < ed[i - 1] && kk < ed[i]; ++jj, ++kk) {
            if (cur == k) {
                break;
            }
            --cur;
            par[kk] = jj;
        }
    }
    if (cur != k) {
        cout << -1 << endl;
        return 0;
    }
    printf("%d\n", n);
    for (int i = 1; i < n; ++i) {
        printf("%d %d\n", i + 1, par[i] + 1);
    }
    return 0;
}