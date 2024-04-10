#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const ll kInf = 1e18;

template <typename T, bool is_max_ver = false>
class MinQueue {
  public:
    MinQueue(const T &id = default_id_())
        : head_({{id, id}}), tail_(head_) {}

    // returns id if there's nothing (logically) in the queue
    T top() const {
        return min_or_max_(head_.top().second, tail_.top().second);
    }

    void push(T x) { push_(tail_, x); }

    void pop() {
        if (size(head_) == 1) {
            while (size(tail_) > 1) {
                push_(head_, tail_.top().first);
                tail_.pop();
            }
        }
        assert(size(head_) > 1);
        head_.pop();
    }

  private:
    stack<pair<T, T>> head_, tail_;

    static T default_id_() {
        return is_max_ver ? numeric_limits<T>::min()
            : numeric_limits<T>::max();
    }

    static const T &min_or_max_(const T &x, const T &y) {
        return is_max_ver ? max(x, y) : min(x, y);
    }

    static void push_(stack<pair<T, T>> &v, T x) {
        v.push({x, min_or_max_(x, v.top().second)});
    }
};

template <typename T>
using MaxQueue = MinQueue<T, true>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<pii> b(m);
    for (auto &[pos, cap] : b) cin >> pos >> cap;

    sort(ALL(a));
    sort(ALL(b));

    vector<ll> a_pre(n + 1);
    for (int i = 0; i < n; i++) {
        a_pre[i + 1] = a_pre[i] + a[i];
    }

    vector dp(m + 1, vector<ll>(n + 1, kInf));
    dp[0][0] = 0;
    for (int j = 0; j < m; j++) {
        auto [pos, cap] = b[j];

        int fst_r = int(upper_bound(ALL(a), pos) - begin(a));
        auto f = [&](int i) {
            ll ans = 0;
            if (i > fst_r) {
                ans += (a_pre[i] - a_pre[fst_r]) - ll(i - fst_r) * pos;
                i = fst_r;
            }
            ans += ll(i) * pos - a_pre[i];
            return ans;
        };

        MinQueue<ll> mq;
        // dp[j][i] = max_{i' <= i}(dp[j][i'] + f(i) - f(i'))
        for (int i = 0; i <= n; i++) {
            if (i > cap) mq.pop();
            mq.push(dp[j][i] - f(i));
            dp[j + 1][i] = f(i) + mq.top();
        }
    }

    if (dp[m][n] == kInf) cout << -1;
    else cout << dp[m][n];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}