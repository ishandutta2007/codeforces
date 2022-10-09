#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct mymap {
    vector<long long> who;
    vector<int> val;

    const int a = 321412;

    int& operator[](long long ind) {
        int c = (1ll * a * ind) % who.size();
        while (who[c] != -1 && who[c] != ind) {
            ++c;
            if (c == who.size())
                c = 0;
        }
        who[c] = ind;
        return val[c];
    }

    mymap(int n) {
        who.resize(n, -1);
        val.resize(n);
    }
};

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    const int C = 333;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    const int s1 = 2e5 + 239;
    const int s2 = 1003;
    for (int i = -C; i <= C; ++i) {
        mymap cnt(s1);
        // unordered_map<long long, int> cnt(2 * n);
        for (int j = 0; j < n; ++j)
            cnt[a[j] - 1ll * i * j]++;
        for (auto i : cnt.val)
            ans = max(ans, i);
    }
    for (int i = 0; i < n; ++i) {
        // unordered_map<long long, int> res(4 * C);
        mymap res(s2);
        for (int k = 1; k <= C; ++k) {
            if (i + k < n) {
                if ((a[i + k] - a[i]) % k == 0)
                    res[(a[i + k] - a[i]) / k]++;
            }
            if (i - k >= 0) {
                if ((a[i] - a[i - k]) % k == 0)
                    res[(a[i] - a[i - k]) / k]++;
            }
        }
        for (auto i : res.val)
            ans = max(ans, i + 1);
    }
    cout << n - ans << '\n';
}