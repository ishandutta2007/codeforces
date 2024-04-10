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
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 1e5+7;
ii p[N];
int t[N], dp[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int r, n;
    cin >> r >> n;
    int ptr = 0; // first not used
    int mx = -N;
    p[0] = mp(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        cin >> p[i].x >> p[i].y;                                        
        while (ptr < i && 2 * (r - 1) <= t[i] - t[ptr]) {
            mx = max(mx, dp[ptr]);
            ptr++;
        }   
        dp[i] = mx + 1;
        for (int j = ptr; j < i; ++j) {
            if (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= t[i] - t[j] && dp[j] >= 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }   
        }   
        ans = max(ans, dp[i]);
    }   
    cout << ans << endl;
}