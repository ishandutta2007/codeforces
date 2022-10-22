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
const int N = 1e5 + 7;
int a[N], b[N];
void solve() {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        int l = N, r = -1;    
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                l = min(l, i);
                r = max(r, i);
            }   
        }   
        if (l == -1) {
            cout << "YES\n";
            return;
        }   
        for (int i = l; i <= r; ++i) {
            if (a[i] - b[i] != a[l] - b[l]) {
                cout << "NO\n";
                return;
            }   
        }   
        if (a[l] > b[l]) {
            cout << "NO\n";
            return;
        }   
        cout << "YES\n";
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) solve();
}