#include <bits/stdc++.h>

// Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
// Problem: B2: Social Network (hard version) (https://codeforces.com/contest/1234/problem/B2)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    set<int> act;
    deque<int> screen;
    for (int i = 0; i < n; ++i) {
        int j; cin >> j; --j;
        auto it = act.find(j);
        if (it != end(act))
            continue;

        if (screen.size() == k) {
            auto x = screen.front();
            screen.pop_front();
            act.erase(x);
        }

        act.insert(j);
        screen.push_back(j);
    }

    cout << screen.size() << '\n';
    for (auto it = rbegin(screen); it != rend(screen); ++it)
        cout << (*it + 1) << ' ';
    cout << '\n';

    return 0;
}