#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
int n, x, y;
int a[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    #endif

    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (x > y) {
        cout << n << '\n';
    }   
    else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += a[i] <= x;
        }   
        cout << ((cnt + 1) >> 1) << '\n';
    }   
    #ifdef HOME
        cout << "TIME: " << (double)clock() / CLOCKS_PER_SEC << '\n';  
    #endif
}