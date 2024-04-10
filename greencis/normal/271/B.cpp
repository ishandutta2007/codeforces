#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int u[200005],cnt[200005];
int n,m,a[505][505],ans = 2e9;

int main()
{
    for (int i = 2; i < 200005; ++i) u[i] = 1;
    for (int i = 2; i < 200005; ++i) {
        if (!u[i]) continue;
        for (int j = i + i; j < 200005; j += i) u[j] = 0;
    }
    int prev = 1000000;
    for (int i = 200004; i >= 1; --i) {
        if (u[i]) prev = i;
        cnt[i] = prev - i;
    }
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j)
            cur += cnt[a[i][j]];
        ans = min(ans, cur);
    }

    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j)
            cur += cnt[a[j][i]];
        ans = min(ans, cur);
    }

    cout << ans;

    return 0;
}