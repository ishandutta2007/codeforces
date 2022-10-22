#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int mx = 0, del = 0;
        for (int i = 0; i < n; ++i) {
            int d, h;
            cin >> d >> h;
            mx = max(mx, d);
            del = max(del, d - h);
        }   
        if (mx < x && del == 0) 
            cout << -1 << endl;
        else if (mx >= x)
            cout << 1 << endl;
        else {
            x -= mx;
            cout << (x + del - 1) / del + 1 << endl;
        }   
    }   
}