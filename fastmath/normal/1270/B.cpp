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
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int l = -1, r = -1;

        const int INF = 1e18 + 7;
        int b = -INF;
        int pos = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (b < a[i] - i) {
                b = a[i] - i;
                pos = i;
            }   
            if (b - a[i] + i - 1 >= 0) {
                l = i;
                r = pos;
            }
        }   
        
        b = -INF;
        pos = -1;
        for (int i = 0; i < n; ++i) {
            if (b < a[i] + i) {
                b = a[i] + i;
                pos = i;
            }   
            if (b - a[i] - i - 1 >= 0) {
                l = pos;
                r = i;
            }   
        }

        if (l == -1) {
            cout << "NO\n";
        }   
        else {
            cout << "YES\n";
            cout << l + 1 << ' ' << r + 1 << '\n';
        }   
    }   
}