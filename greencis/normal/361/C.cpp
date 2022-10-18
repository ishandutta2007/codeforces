#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a[5005],ans[5005],t[5005],x[5005],y[5005],z[5005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < 5005; ++i) ans[i] = 1e9;
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> x[i] >> y[i] >> z[i];
        --x[i]; --y[i];
        if (t[i] == 1) {
            for (int j = x[i]; j <= y[i]; ++j) a[j] += z[i];
        } else {
            for (int j = x[i]; j <= y[i]; ++j) ans[j] = min(ans[j], z[i] - a[j]);
        }
    }

    for (int i = 0; i < n; ++i) a[i] = ans[i];
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            for (int j = x[i]; j <= y[i]; ++j) a[j] += z[i];
        } else {
            int mx = -2e9;
            for (int j = x[i]; j <= y[i]; ++j) mx = max(mx, a[j]);
            if (mx != z[i]) { puts("NO"); exit(0); }
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);

    return 0;
}