#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int a[N][N];
int r[N][N], c[N][N];
int rr[N], cc[N];
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
        for (int j = 0; j < m; ++j) r[i][j] = a[i][j];
        sort(r[i], r[i] + m);
        rr[i] = unique(r[i], r[i] + m) - r[i];
    }   
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) c[j][i] = a[i][j];
        sort(c[j], c[j] + n);
        cc[j] = unique(c[j], c[j] + n) - c[j];
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ans = max(rr[i], cc[j]);
            ans = max(ans, (lower_bound(r[i], r[i] + rr[i], a[i][j]) - r[i]) + (cc[j] - (upper_bound(c[j], c[j] + cc[j], a[i][j]) - c[j])) + 1);
            ans = max(ans, (lower_bound(c[j], c[j] + cc[j], a[i][j]) - c[j]) + (rr[i] - (upper_bound(r[i], r[i] + rr[i], a[i][j]) - r[i])) + 1);
            cout << ans << ' ';
        }   
        cout << '\n';
    }           
}