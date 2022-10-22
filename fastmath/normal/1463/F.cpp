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

const int N = 57;
int dp[N][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;

    auto relax = [&] (int &a, int b) {
        a = max(a, b);
    };  

    int p = x + y;
    vector <int> cnt(x + y);
    for (int i = 0; i < p; ++i)
        cnt[i] = n/p + (i < n%p);

    auto solve = [&] (vector <int> a) {
        if (a.size() == 1)
            return a.back();
        int n = a.size();
        int ans = 0;
        for (int f = 0; f < 2; ++f) {
            memset(dp, 0, sizeof dp);
            if (f) {
                dp[0][1] = a[0];
            }   
            for (int i = 0; i + 1 < n; ++i) {
                for (int t = 0; t < 2; ++t) {
                    for (int add = 0; t + add < 2; ++add) {
                        relax(dp[i + 1][add], dp[i][t] + a[i + 1] * add);
                    }   
                }   
            }   
            for (int r = 0; f + r < 2; ++r)
                relax(ans, dp[n - 1][r]);
        }   
        return ans;
    };

    int ans = 0;
    int G = __gcd(x, y);
    for (int s = 0; s < G; ++s) {
        int u = s;
        vector <int> a;
        do {
            a.app(cnt[u]);                    
            u = (u + x) % p;
        } while (u != s);
        ans += solve(a);
    }   
    cout << ans << endl;
}