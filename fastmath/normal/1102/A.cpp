#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    cout << ((n * (n + 1) / 2) & 1) << '\n';

    #ifdef HOME
        cout << "TIME: " << (double)clock() / CLOCKS_PER_SEC << '\n';  
    #endif
}