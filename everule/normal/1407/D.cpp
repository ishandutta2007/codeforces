#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
#define trav(e, x) for (const auto &(e) : (x))
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define lc(i) 2*i
#define rc(i) 2*i+1
//#define int long long
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vii = vector<ii>;

const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9 + 5;

signed main() {
    FAST_IO;
    //setIO("input.txt", "output.txt");

    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    stack<ii> bigger, smaller;
    vi dp(n);
    iota(all(dp), 0);
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!bigger.empty() && bigger.top().first < h[i]){
            if(last!=bigger.top().first){
                dp[i] = min(dp[i], dp[bigger.top().second] + 1);
                last = bigger.top().first;   
            }
            bigger.pop();
        }
        if (!bigger.empty()) dp[i] = min(dp[i], dp[bigger.top().second] + 1);
        last = -1;
        bigger.emplace(h[i], i);
        while (!smaller.empty() && smaller.top().first > h[i]){
            if(last!=smaller.top().first){
                dp[i] = min(dp[i], dp[smaller.top().second] + 1);
                last = smaller.top().first;   
            }
            smaller.pop();
        }
        if (!smaller.empty()) dp[i] = min(dp[i], dp[smaller.top().second] + 1);
        smaller.emplace(h[i], i);
    }
    cout << dp[n - 1];
}