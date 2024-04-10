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
        int n;
        cin >> n;
        vector <ii> a(n + 1);
        a[0] = mp(0, 0);
        for (int i = 1; i <= n; ++i)
            cin >> a[i].f >> a[i].s;
        string ans = "YES";
        for (int i = 0; i < n; ++i) {
            if (a[i + 1].s - a[i].s > a[i + 1].f - a[i].f) {
                ans = "NO";
            }   
            if (a[i + 1].f < a[i].f || a[i + 1].s < a[i].s) {
                ans = "NO";
            }   
        }   
        cout << ans << endl;
    }   
}