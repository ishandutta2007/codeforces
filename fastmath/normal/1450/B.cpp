#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    #define x first
    #define y second

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <ii> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].x >> a[i].y;
        }   

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int mx = 0;
            for (int j = 0; j < n; ++j) {
                mx = max(mx, abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
            }   
            if (mx <= k) {
                ans = 1;
            }   
        }   
        cout << ans << endl;                                
    }   
}