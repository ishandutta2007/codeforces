#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m,a[105][105];
char s[105][105];

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n;++i)cin>>s[i+1]+1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = (s[i][j] == 'W') + a[i - 1][j] + a[i][j - 1] - a[i - 1][j-1];
        }
    }
    int mnx=1e9,mxx=-1e9,mny = 1e9,mxy = -1e9;
    for(int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == 'B')
                mnx = min(mnx, j), mxx = max(mxx, j), mny = min(mny, i), mxy = max(mxy, i);
    if (mnx==int(1e9)) {cout<<1;return 0;}
    if (mxx - mnx + 1 > mxy - mny + 1) {
        int len = mxx - mnx + 1;
        if (len > n) {cout<<-1;return 0;}
        int ans = 1e9;
        for (int i = max(1, mxy - len + 1); i <= mny && i + len - 1 <= n; ++i)
           ans = min(ans, a[i + len - 1][mxx] - a[i - 1][mxx] - a[i + len - 1][mnx - 1] + a[i - 1][mnx - 1]);
        cout << ans;
    } else {
        int len = mxy - mny + 1;
        if (len > m) {cout<<-1;return 0;}
        int ans = 1e9;
        for (int i = max(1, mxx - len + 1); i <= mnx && i + len - 1 <= m; ++i)
           ans = min(ans, a[mxy][i + len - 1] - a[mxy][i - 1] - a[mny - 1][i + len - 1] + a[mny - 1][i - 1]);
        cout << ans;
    }
}