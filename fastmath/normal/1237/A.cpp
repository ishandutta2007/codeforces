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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    bool t = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x & 1) {
            if (t) cout << x / 2 - (x < 0) << '\n';
            else {
                cout << (x / 2) + 1 - (x < 0) << '\n';
            }   
            t ^= 1;
        }   
        else {
            cout << x / 2 << '\n';
        }   
    }
}