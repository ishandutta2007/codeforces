#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n;
    cin >> n;
    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < n; ++i) {
        char t;
        cin >> t;
        if (t == '+') {
            int x, y;
            cin >> x >> y;
            if (y < x) swap(x, y);
            mx1 = max(mx1, x);
            mx2 = max(mx2, y);
        }
        else {
            int x, y;
            cin >> x >> y;
            if (y < x) swap(x, y);
            if (mx1 <= x && mx2 <= y) {
                cout << "YES\n";
            }   
            else {
                cout << "NO\n";
            }   
        }   
    }    
}