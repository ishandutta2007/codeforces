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

const int N = 101, INF = 1e15;

ii get(vector <int> a, int add, int k, int m) {
    int sum = 0;
    for (int e : a)
        sum += e;
    vector <ii> ans;
    ans.app(mp(add, add));
    for (int i = 0; i < k; ++i) {
        int l = sum + 1, r = sum + m;
        for (auto e : ans) {
            l += e.f;
            r += e.s;
        }   
        ans.app(mp(l, r));
    }   
    return ans.back();
}   

ii dp[N], sum[N];
void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    if (a == b) {
        cout << "1 " << a << '\n';
        return;
    }   

    dp[0] = sum[0] = {a, a};
    for (int i = 1; ; ++i) {
        dp[i] = {1, m};
        for (int j = 0; j < i; ++j) {
            dp[i].f += dp[j].f;
            dp[i].s += dp[j].s;
        }   
        sum[i] = {sum[i - 1].f + dp[i].f, sum[i - 1].s + dp[i].s};

        if (dp[i].f <= b && b <= dp[i].s) {
            vector <int> ans = {a};
            int sum = a;

            for (int j = 0; j < i; ++j) {
                int l = 0;
                int r = m;
                while (l < r - 1) {         
                    int mid = (l + r) >> 1;
                    auto t = get(ans, sum + mid, i - ans.size(), m);
                    if (t.s < b)
                        l = mid;
                    else
                        r = mid;
                }   
                int x = sum + r;
                ans.app(x);
                sum += x;
            }   

            cout << ans.size() << '\n';
            for (int e : ans)
                cout << e << ' ';
            cout << '\n';

            return;
        }   
        if (b < dp[i].f) {
            cout << "-1\n";
            return;
        }   
    }           
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int q;
    cin >> q;
    while (q--) 
        solve();
}