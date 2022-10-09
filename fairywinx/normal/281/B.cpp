#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;
 
signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    auto comp = [] (const pair<long long, long long> a, const pair<long long, long long> b) {
        return (long double) a.first / a.second < (long double) b.first / b.second;
    };
    auto comp_abs = [] (const pair<long long, long long> a, const pair<long long, long long> b) {
        return (long double) abs(a.first) / a.second < (long double) abs(b.first) / b.second;
    };

    auto sub = [] (const pair<int, int> a, const pair<int, int> b) {
        return make_pair(1ll * a.first * b.second - 1ll * b.first * a.second, 1ll * a.second * b.second);
    };

    int n;
    pair<int, int> x;
    cin >> x.first >> x.second >> n;
    pair<int, int> ans = {0, 1};
    pair<long long, long long> razn = sub(ans, x);

    for (int i = 1; i <= n; ++i) {
        long long it = (1ll * x.first * i + x.second - 1) / x.second;
        if (comp_abs(sub(make_pair(it - 1, i), x), razn)) {
            razn = sub(make_pair(it - 1, i), x);
            ans = make_pair(it - 1, i);
        }
        if (comp_abs(sub(make_pair(it, i), x), razn)) {
            razn = sub(make_pair(it, i), x);
            ans = make_pair(it, i);
        }
    }
    cout << ans.first << '/' << ans.second << '\n';
}