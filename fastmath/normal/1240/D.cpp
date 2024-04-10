    #include<bits/stdc++.h>
    using namespace std;
    //#define HOME
    #define f first
    #define s second
    #define int long long
    const int N = 3e5 + 7;
    mt19937 rnd(2007);
    int n, a[N], f[N];
    int solve(int l, int r) {
        if (l == r) return 0;
        int m = (l + r) >> 1;
        int ans = solve(l, m) + solve(m + 1, r);
        vector <int> cur, h = {0};
        map <int, int> cnt;
        for (int i = m; i >= l; --i) {
            if (cur.size() && cur.back() == a[i]) {
                cur.pop_back(); h.pop_back();
            }
            else {
                cur.push_back(a[i]); h.push_back(h.back() + a[i] * f[h.size()]);
            }
            ++cnt[h.back()];
        }
        cur.clear(); h = {0};
        for (int i = m + 1; i <= r; ++i) {
            if (cur.size() && cur.back() == a[i]) {
                cur.pop_back(); h.pop_back();
            }
            else {
                cur.push_back(a[i]); h.push_back(h.back() + a[i] * f[h.size()]);
            }
            ans += cnt[h.back()];
        }
        return ans;
    }
    void solve() {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(0, n - 1) << '\n';
    }
    signed main() {
        #ifdef HOME
        freopen("input.txt", "r", stdin);
        #else
        ios_base::sync_with_stdio(0); cin.tie(0);
        #endif // HOME
        for (int i = 0; i < N; ++i) f[i] = rnd();
        int t; cin >> t; while (t--) solve();
    }