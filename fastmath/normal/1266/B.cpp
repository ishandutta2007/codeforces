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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        bool c = 0;
        for (int d = 1; d <= 6; ++d) {
            int up = 21 - d;
            if (up <= n && (n - up) % 14 == 0)
                c = 1;
        }   
        if (c) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
}