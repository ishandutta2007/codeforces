#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int x[N], w[N];
int l[N], r[N];
int n;
int dp[N];
struct Event {
    bool t;
    int i, x;
};  
bool comp(Event a, Event b) {
    return a.x < b.x || (a.x == b.x && a.t < b.t);
}   
int solve() {
    vector <Event> v;
    for (int i = 0; i < n; ++i) {
        v.push_back({1, i, l[i]});
        v.push_back({0, i, r[i]});        
    }   
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    for (auto e : v) {
        if (e.t) {
            dp[e.i] = ans + 1;
        }
        else {
            ans = max(ans, dp[e.i]);
        }
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> w[i];
    for (int i = 0; i < n; ++i) {
        l[i] = x[i] - w[i];
        r[i] = x[i] + w[i];
    }   
    cout << solve() << '\n';
}