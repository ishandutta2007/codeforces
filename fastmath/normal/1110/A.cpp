#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int a[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int b, k;
    cin >> b >> k;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    int c = 1;   
    for (int i = k - 1; i >= 0; --i) {
        ans += a[i] * c;
        c = (c * b) % 2;
    }
    if (ans % 2 == 0) cout << "even\n";
    else cout << "odd\n";
}