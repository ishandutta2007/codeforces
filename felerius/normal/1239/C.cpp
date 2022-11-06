#include <bits/stdc++.h>

// Contest: Codeforces Round #594 (Div. 1) (https://codeforces.com/contest/1239)
// Problem: C: Queue in the Train (https://codeforces.com/contest/1239/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <class T> using minq = priority_queue<T, vector<T>, greater<>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll p; cin >> n >> p;
    minq<tuple<ll, int, int>> evts;
    minq<int> waiting;
    queue<int> queue;
    set<int> queue_set;
    for (int i = 0; i < n; ++i) {
        ll ti; cin >> ti;
        evts.emplace(ti, 0, i);
    }

    vector<ll> water(n);
    while (!evts.empty()) {
        auto [ti, t, idx] = evts.top(); evts.pop();
        if (t == 1) {
            auto ret = queue.front(); queue.pop();
            queue_set.erase(ret);
            water[ret] = ti;
            if (!waiting.empty()) {
                auto i = waiting.top();
                if (queue_set.empty() || *begin(queue_set) > i) {
                    waiting.pop();
                    queue.push(i);
                    queue_set.emplace(i);
                }
            }
            if (!queue.empty())
                evts.emplace(ti + p, 1, -1);
        } else {
            if (queue_set.empty() || *begin(queue_set) > idx) {
                queue.push(idx);
                queue_set.emplace(idx);
                if (queue.size() == 1)
                    evts.emplace(ti + p, 1, -1);
            } else
                waiting.emplace(idx);
        }
    }

    for (auto i : water)
        cout << i << ' ';
    cout << '\n';
    return 0;
}