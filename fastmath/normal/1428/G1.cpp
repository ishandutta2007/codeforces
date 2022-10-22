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

int cost[6];

const int N = 1e6+7, INF = 1e18+7;
int dp[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int k;
    cin >> k;
    for (int i = 0; i < 6; ++i)
        cin >> cost[i];

    for (int i = 1; i < N; ++i)
        dp[i] = -INF;
    auto add = [&] (int we, int co) {
        for (int i = N - we - 1; i >= 0; --i) {
            if (dp[i] != -INF) {
                dp[i + we] = max(dp[i + we], dp[i] + co);
            }
        }   
    };

    int w = 1;
    for (int d = 0; d < 6; ++d) {
        // (3 * w, f[d])
        int h = 3 * (k - 1);
        int cur = 1;
        while (h) {
            cur = min(cur, h);
            add(3 * w * cur, cost[d] * cur);
            h -= cur;
            cur <<= 1;
        }   
        w *= 10;
    }   

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 0; i <= x; ++i) {
            int add = 0;
            int t = i;
            for (int d = 0; d < 6; ++d) {
                int c = t % 10;
                if (c % 3 == 0) {
                    add += (c/3) * cost[d];
                }   
                t /= 10;
            }   
            ans = max(ans, dp[x - i] + add);
        }
        cout << ans << endl;
    }   
}