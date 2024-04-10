#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    ios :: sync_with_stdio(false);
    cin >> t;
    while(t--) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    for(int i = 30; ~i; i--) {
        int d1 = (a >> i) & 1, d2 = (b >> i) & 1;
        if(d1 + d2 == 0) ans <<= 1;
        else if(d1 == 1 && d2 == 0) ans = (ans << 1) | ("101"[n % 3] - '0');
        else if(d1 == 0 && d2 == 1) ans = (ans << 1) | ("011"[n % 3] - '0');
        else ans = (ans << 1) | ("110"[n % 3] - '0');
    }
    cout << ans << endl;
    }
}