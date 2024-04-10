#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
const int N = 2e5 + 7;
int a[N], b[N], p[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 0; i < N; ++i) p[i] = -1;
    for (int i = 1; i <= n; ++i) {
        if (b[i]) {
            p[b[i]] = i;
        }   
    }   
    if (p[1] != -1) {
        bool c = 1;
        for (int i = p[1]; i <= n; ++i) {
            c &= b[i] == 1 + i - p[1];
        }   
        if (c) {
            bool c = 1;
            int f = n - p[1] + 2;
            for (int i = f; i <= n; ++i) {
                int w = i - f + 1;
                if (p[i] != -1) {
                    c &= w > p[i];
                }   
            }   
            if (c) {
                cout << p[1] - 1 << '\n';
                exit(0);
            }   
        }   
    }   
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        if (p[i] != -1) {
            ans = max(ans, p[i] + n - i + 1);
        }
    }   
    cout << ans << '\n';
}