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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;

    const int INF = 1e18;

    while (t--) {
        int pos = 0, w = 0;
        int n;
        cin >> n;

        int ans = 0;
        int prv = 0;

        vector <int> t(n), x(n);
        for (int i = 0; i < n; ++i) 
            cin >> t[i] >> x[i];
        
        for (int i = 0; i < n; ++i) {
            int di = t[i] - prv;
            if (di >= abs(pos - w)) {

                int tot = INF;
                if (i + 1 < n)
                    tot = t[i + 1] - t[i];

                pos = w;
                w = x[i];

                ans += abs(pos - w) <= tot;
            }   
            else {
                int tot = INF;
                if (i + 1 < n)
                    tot = t[i + 1] - prv;

                if (pos > w) {                    
                    ans += max(w, pos - tot) <= x[i] && x[i] <= pos - di;
                    pos -= di;
                }
                else {
                    ans += pos + di <= x[i] && x[i] <= min(w, pos + tot);
                    pos += di;
                }                    
            }

            prv = t[i];
        }   
        cout << ans << endl;
    }   
}