#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

struct Event {
    int idx, l, r;

    bool operator<(const Event& other) const {
        if (r != other.r)
            return r < other.r;
        return idx < other.idx;
    }
};

constexpr int MAXC = 1'000'001;
int t[MAXC + 1];
inline void add(int x, int val) {
    for (; x <= MAXC; x |= x + 1)
        t[x] += val;
}
inline int get(int x) {
    int sum = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        sum += t[x];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({0, l, r});
    }
    vector<int> ans(m, n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> pts(k);
        for (int j = 0; j < k; ++j)
            cin >> pts[j];
        for (int j = 0; j <= k; ++j) {
            int L = (j == 0 ? 0 : pts[j - 1] + 1);
            int R = (j == k ? MAXC : pts[j] - 1);
            if (L <= R)
                events.push_back({i + 1, L, R});
        }
    }
    sort(all(events));
    for (auto& e : events) {
        if (e.idx == 0)
            add(e.l, 1);
        else {
            ans[e.idx - 1] -= get(e.r) - get(e.l - 1);
        }
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}