#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> go;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        int op = n - i - 1;
        if (op != i) {
            for (int j = 0; j < m; ++j) {
                go.emplace_back(i, j);
                go.emplace_back(op, m - j - 1);
            }
        }
        else {
            for (int j = 0; j < (m + 1) / 2; ++j) {
                go.emplace_back(i, j);
                if (m - j - 1 != j) go.emplace_back(i, m - j - 1);
            }
        }
    }
    /*vector <vector <int>> ck(n, vector <int> (m));
    for (auto p : go) {
        assert(0 <= p.first && p.first < n && 0 <= p.second && p.second < m);
        assert(ck[p.first][p.second] == 0);
        ck[p.first][p.second] = 1;
    }
    assert(go.size() == n * m);
    set <pair <int, int>> kek;
    for (int i = 1; i < go.size(); ++i) {
        int dx = go[i].first - go[i - 1].first;
        int dy = go[i].second - go[i - 1].second;
        if (kek.count({dx, dy})) {
            assert(false);
        }
        else {
            kek.insert({dx, dy});
        }
    }*/
    for (auto p : go) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}