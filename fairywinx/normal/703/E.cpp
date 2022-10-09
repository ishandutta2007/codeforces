#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int C = 7777;
const int N = 1e3 + 228;

pair<int, int> lst[N][C];

vector<int> cnt;

vector<int> who(int c) {
    vector<int> res;
    for (auto i : cnt) {
        res.push_back(c % (i + 1));
        c /= (i + 1);
    }
    return res;
}

int to(vector<int> a) {
    int res = 0;
    int now = 1;
    for (int i = 0; i < (int) a.size(); ++i) {
        res += now * a[i];
        now *= (cnt[i] + 1);
    }
    return res;
}

int to(int a, int b) {
    int res = 0;
    int now = 1;
    for (int i = 0; i < (int) cnt.size(); ++i) {
        res += now * min(cnt[i], a % (cnt[i] + 1) + b % (cnt[i] + 1));
        a /= (cnt[i] + 1);
        b /= (cnt[i] + 1);
        now *= (cnt[i] + 1);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;
    long long last_k = k;
    vector<long long> Who;
    for (long long i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            cnt.emplace_back(0);
            Who.emplace_back(i);
            while (k % i == 0) {
                cnt.back()++;
                k /= i;
            }
        }
    }
    if (k != 1) {
        cnt.emplace_back(1);
        Who.emplace_back(k);
    }

    vector<vector<int>> a(n);
    vector<int> b(n);
    vector<long long> u;
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        u.push_back(c);
        for (auto j : Who) {
            int res = 0;
            while (c % j == 0) {
                ++res;
                c /= j;
            }
            a[i].push_back(res);
        }
        b[i] = to(a[i]);
    }
    if (last_k == 1) {
        cout << 1 << '\n' << min_element(all(u)) - u.begin() + 1 << '\n';
        return 0;
    }
    int max_val = to(cnt);
    array<vector<pair<int, long long>>, 2> dp;
    dp[0].resize(max_val + 1, {N, N});
    dp[0][0] = {0, 0};
    fill(lst[0], lst[0] + max_val + 1, make_pair(-1, -1));
    for (int i = 0; i < n; ++i) {
        int z = i & 1;
        dp[z ^ 1] = vector<pair<int, long long>> (max_val + 1, {N, N});
        for (int j = 0; j <= max_val; ++j) {
            if (dp[z ^ 1][j] > dp[z][j]) {
                dp[z ^ 1][j] = dp[z][j];
                if (j != 0)
                    lst[i + 1][j] = {j, i};
                else
                    lst[i + 1][j] = {-1, -1};
            }
            
            auto val = to(j, b[i]);
            if (dp[z ^ 1][val] > make_pair(dp[z][j].first + 1, dp[z][j].second + u[i])) {
                dp[z ^ 1][val] = make_pair(dp[z][j].first + 1, dp[z][j].second + u[i]);
                lst[i + 1][val] = {j, i};
            }
        }
    }
    if (dp[n & 1].back().first == N) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[n & 1].back().first << '\n';
    vector<int> ans;
    int ind = n, val = max_val;
    while (ind != -1) {
        auto z = lst[ind][val];
        if (z.second == -1)
            break;
        if (val != z.first)
            ans.push_back(z.second + 1);
        ind = z.second, val = z.first;
    }
    for (int i = 0; i < (int) ans.size(); ++i) {
        for (int j = 0; j < (int) cnt.size(); ++j) {
            while (u[ans[i] - 1] % Who[j] == 0) {
                cnt[j] = max(0, cnt[j] - 1);
                u[ans[i] - 1] /= Who[j];
            }
        }
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}