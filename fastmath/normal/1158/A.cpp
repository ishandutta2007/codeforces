#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n, m;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    int sum = 0;
    set <pair <int, int> > ms;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];            
        mx = max(mx, a[i]);
    }       
    sort(a, a + n);
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b, b + m);
    int ans = sum * m;
    int ptr = n - 1, cur = m - 1;

    if (b[0] < mx) {
        cout << "-1\n";
        exit(0);
    }   

    for (int i = m - 1; i >= 0; --i) {
        if (b[i] <= mx) break;
        while (ptr != -1 && !cur) {
            --ptr;
            cur = m - 1;
        }   
        if (ptr == -1) {
            cout << "-1\n";
            exit(0);
        }   
        ans += b[i] - a[ptr];
        --cur;
    }   
    cout << ans << '\n';
}