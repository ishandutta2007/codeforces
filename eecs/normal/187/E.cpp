#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, lim, s, a[maxn];

int main() {
    scanf("%d %d %d", &n, &lim, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    auto solve = [&](int s, int lim) {
        long long ans = LLONG_MAX, cur = 0;
        priority_queue<int> Q;
        priority_queue<int, vector<int>, greater<>> cand;
        auto ins = [&](int x) {
            if (!Q.empty() && x < Q.top()) Q.push(x), cur += x;
            else cand.push(x);
        };
        auto query = [&](int k) {
            while (Q.size() < k) cur += cand.top(), Q.push(cand.top()), cand.pop();
            while (Q.size() > k) cur -= Q.top(), cand.push(Q.top()), Q.pop();
            return cur;
        };
        int ed;
        for (int i = s + 1; i <= n; i++) {
            int k = lim - min(s - 1, max(1, lim)) - (n - i);
            if (k >= 0 && k < max(1, i - s - 1)) {
                long long v = 2 * (query(k) + a[n] - a[1]) + a[s] - a[i];
                if (v < ans) ans = v, ed = i;
            }
            if (i > s + 1) ins(a[i] - a[i - 1]);
        }
        if (ans > 1e18) return make_pair(ans, vector<int>{});
        vector<int> res = {s}, rev;
        int k = lim - min(s - 1, max(1, lim)) - (n - ed);
        vector<pair<int, int>> diff;
        for (int i = s + 2; i < ed; i++) {
            diff.emplace_back(a[i] - a[i - 1], i);
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < k; i++) {
            rev.push_back(diff[i].second);
        }
        sort(rev.begin(), rev.end());
        for (int i = min(s - 1, max(1, lim)); i; i--) {
            res.push_back(i);
        }
        for (int i = min(s, max(1, lim) + 1); i < s; i++) {
            res.push_back(i);
        }
        for (int i = s + 1; i < ed; i++) {
            res.push_back(i);
        }
        for (int i = 0, j; i < rev.size(); i = j) {
            for (j = i; j < rev.size() && rev[i] - i == rev[j] - j; j++);
            reverse(res.begin() + rev[i] - 2, res.begin() + rev[i] + j - i - 1);
        }
        for (int i = n; i >= ed; i--) {
            res.push_back(i);
        }
        return make_pair(ans, res);
    };
    auto ans = solve(s, lim);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = 1e9 - a[i];
    }
    auto _ans = solve(n - s + 1, n - lim - 1);
    for (int &x : _ans.second) x = n - x + 1;
    ans = min(ans, _ans);
    if (ans.first > 1e18) puts("-1"), exit(0);
    printf("%lld\n", ans.first);
    for (int x : ans.second) {
        if (x ^ s) printf("%d ", x);
    }
    return 0;
}