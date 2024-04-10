#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, s, m, k;
    cin >> n >> s >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int>> b(s);
    for (int i = 0; i < s; ++i) {
        cin >> b[i].first >> b[i].second;
        --b[i].first;
        --b[i].second;
    }
    sort(b.begin(), b.end(), [&] (pair <int, int> i, pair <int, int> j) {
        if (i.first != j.first) return i.first < j.first;
        return i.second > j.second;
    });
    int mx = -1;
    vector <pair <int, int>> c;
    for (int i = 0; i < s; ++i) {
        if (b[i].second > mx) {
            c.push_back(b[i]);
            mx = b[i].second;
        }
    }
    vector <int> sorted = a;
    sort(sorted.begin(), sorted.end());
    b = c;
    s = b.size();
    m = min(m, s);
    vector <int> who(s, -1);
    for (int i = 0; i < s; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (b[j].second >= b[i].first) who[i] = j;
        }
    }
    int low = -1, high = n;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        vector <int> pref(n + 1);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] + (a[i - 1] <= sorted[mid]);
        }
        vector <vector <int>> dp(m + 1, vector <int> (s + 1, -Inf));
        dp[0][0] = 0;
        auto get = [&] (int l, int r) {
            return pref[r + 1] - pref[l];
        };

        auto getInter = [] (pair <int, int> a, pair <int, int> b) {
            return make_pair(max(a.first, b.first), min(a.second, b.second));
        };

        vector <vector <int>> mx(m + 1, vector <int> (s + 1, -Inf));
        for (int i = 0; i <= s; ++i) {
            mx[0][i] = 0;
        }
        for (int cnt = 1; cnt <= m; ++cnt) {
            for (int i = cnt; i <= s; ++i) {
                if (i == 1) {
                    dp[cnt][i] = get(b[0].first, b[0].second);
                }
                else {
                    int w = who[i - 1];
                    if (w != -1) {
                        auto p = getInter(b[i - 1], b[w]);
                        int dt = get(p.first, p.second);
                        dp[cnt][i] = dp[cnt - 1][w + 1] - dt + get(b[i - 1].first, b[i - 1].second);
                        dp[cnt][i] = max(dp[cnt][i], mx[cnt - 1][w] + get(b[i - 1].first, b[i - 1].second));
                    }
                    else {
                        dp[cnt][i] = get(b[i - 1].first, b[i - 1].second) + mx[cnt - 1][i - 1];
                    }
                }
                mx[cnt][i] = max(mx[cnt][i - 1], dp[cnt][i]);
            }
        }
        int res = 0;
        for (int cnt = 0; cnt <= m; ++cnt) {
            for (int i = 0; i <= s; ++i) {
                res = max(res, dp[cnt][i]);
            }
        }
        if (res >= k) high = mid;
        else low = mid;
    }

    if (high == n) {
        cout << "-1\n";
    }
    else {
        cout << sorted[high] << '\n';
    }
}