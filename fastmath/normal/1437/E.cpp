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
    const int INF = 1e9+7;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }

    vector <int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        b[i]--;
    }
    b.insert(b.begin(), -1);
    b.app(n);

    auto nvp = [&] (vector <int> a) {

        int n = a.size();
        vector <int> dp(n + 3, INF);
        dp[0] = -INF;
        for (auto x : a) {
            auto t = upper_bound(all(dp), x);
            int p = t - dp.begin();
            dp[p] = x;
        }   

        for (int i = n; i >= 0; --i)
            if (dp[i] != INF)
                return i;
        assert(0);
    };  

    int ans = n - k;
    for (int i = 0; i + 1 < b.size(); ++i) {
        int l = b[i] + 1;
        int r = b[i + 1] - 1;

        int L = -INF;
        if (i)
            L = a[b[i]];
        int R = INF;
        if (b[i + 1] != n)
            R = a[b[i + 1]];

        if (L > R) {
            cout << -1 << endl;
            exit(0);
        }   

        vector <int> t;
        for (int j = l; j <= r; ++j) {
            if (a[j] >= L && a[j] <= R)
                t.app(a[j]);
        }   

        ans -= nvp(t);
    }   
    cout << ans << endl;
}