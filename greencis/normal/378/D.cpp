#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

struct Student {
    int cost, ability, idx;

    bool operator<(const Student& other) const {
        if (cost != other.cost)
            return cost < other.cost;
        return ability < other.ability;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;
    vector<pii> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(all(v));
    vector<Student> stud(n); // cost/ability
    for (int i = 0; i < n; ++i) {
        cin >> stud[i].ability;
    }
    for (int i = 0; i < n; ++i) {
        cin >> stud[i].cost;
        stud[i].idx = i;
    }
    sort(all(stud));

    vector<int> assignment;
    auto check = [&](int x) {
        assignment.assign(m, -1);
        set<pii> bugsToCover;
        for (int i = m - 1; i >= 0; i -= x) {
            bugsToCover.emplace(v[i].first, i);
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            auto [cost, ability, studIdx] = stud[i];
           // cerr << "!!! (" << x << ") " << cost << " " << ability << " " << studIdx << " " << bugsToCover.size() << " " << sum << endl;
            auto it = bugsToCover.lower_bound({ability + 1, -1});
            if (it != bugsToCover.begin()) {
                sum += cost;
                if (sum > s)
                    return false;
                --it;
                int idx = it->second;
                for (int z = 0; z < x && idx - z >= 0; ++z)
                    assignment[v[idx - z].second] = studIdx;
                bugsToCover.erase(it);
            }
        }
        return bugsToCover.empty();
    };

    int L = 1, R = m + 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid))
            R = mid;
        else
            L = mid + 1;
    }
    if (L == m + 1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        check(L);
        for (int x : assignment)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}