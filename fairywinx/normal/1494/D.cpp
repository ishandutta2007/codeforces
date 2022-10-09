#include <algorithm>
#include <iostream>
#include <vector>

#define all(a) a.begin(), a.end()

using namespace std;

struct dsu {
    vector<int> p;
    dsu(int n) {
        p.resize(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    dsu() {}

    int get(int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }

    void merge(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return;
        p[b] = a;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    vector<pair<int, pair<int, int>>> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            c.push_back({a[i][j], {i, j}});
        }
    }
    dsu d(3 * n * n);
    vector<int> ans1(n);
    vector<pair<int, int>> ans2;
    vector<bool> nach(n);
    sort(all(c));
    for (auto i : c) {
        if (i.second.first == i.second.second) {
            ans1[i.second.first] = i.first;
        } else {
            i.second.first = d.get(i.second.first);
            i.second.second = d.get(i.second.second);
            if (i.second.first == i.second.second)
                continue;
            if (ans1[i.second.first] == i.first) {
                ans2.emplace_back(i.second.second + 1, i.second.first + 1);
                nach[i.second.second] = 0;
                d.merge(i.second.first, i.second.second);
            } else if (ans1[i.second.second] == i.first) {
                ans2.emplace_back(i.second.first + 1, i.second.second + 1);
                nach[i.second.first] = 0;
                d.merge(i.second.second, i.second.first);
            } else {
                ans1.push_back(i.first);
                nach.push_back(1);
                nach[i.second.second] = 0;
                nach[i.second.first] = 0;
                ans2.emplace_back(i.second.second + 1, ans1.size());
                ans2.emplace_back(i.second.first + 1, ans1.size());
                d.merge(ans1.size() - 1, i.second.second);
                d.merge(ans1.size() - 1, i.second.first);
            }
        }
    }
    cout << ans1.size() << '\n';
    for (int i : ans1)
        cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < (int) ans1.size(); ++i) {
        if (nach[i])
            cout << i + 1 << '\n';
    }
    for (auto i : ans2)
        cout << i.first << ' ' << i.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
}