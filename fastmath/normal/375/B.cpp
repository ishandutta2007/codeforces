#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5001;
char a[N][N];
int cnt[N];
int f[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }   
    for (int i = 0; i < n; ++i) {
        f[i] = m;
    }   
    int ans = 0;
    for (int l = m - 1; l >= 0; --l) {   
        for (int i = 0; i < n; ++i) {
            if (a[i][l] == '0') {
                --cnt[f[i]];
                f[i] = l;
                ++cnt[f[i]];
            }   
        }   
        int h = n;
        for (int r = l; r < m; ++r) {
            h -= cnt[r];
            ans = max(ans, (r - l + 1) * h);
        }   
    }   
    cout << ans << '\n';
}