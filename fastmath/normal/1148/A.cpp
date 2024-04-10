#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int a, b, c;
    cin >> a >> b >> c;
    int ans1 = 2 * c + 2 * min(a, b) + (a > b);
    int ans2 = 0;
    if (b) ans2 = 1 + 2 * c + 2 * min(a, b - 1) + (a > (b - 1));
    cout << max(ans1, ans2) << '\n';
}