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
const int N = 7001;
map <int, int> d;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++d[a[i]];
    }
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <int> m;
    for (auto e : d) if (e.s > 1) m.app(e.f);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int t : m) {
            if ((a[i] & t) == a[i]) {
                ans += b[i]; break;
            }
        }       
    }   
    cout << ans << '\n';
}