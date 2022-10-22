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

    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        p--;

        // we start from p

        string s;
        cin >> s;
        vector <vector <int> > a(k);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                a[i%k].app(i);
            }   
        }   

        int x, y;
        cin >> x >> y;

        int ans = 1e18;
        for (int del = 0; p < n - del; ++del) {
            int rem = (del + p) % k;
            int l = del + p;
            int cnt = a[rem].end() - lower_bound(all(a[rem]), l);
            ans = min(ans, x * cnt + y * del);
        }   
        cout << ans << endl;
    }   

}