#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int n, st, x, perm[maxn];
mt19937 rnd(time(0));

int main() {
    cin >> n >> st >> x;
    iota(perm + 1, perm + n + 1, 1);
    shuffle(perm + 1, perm + n + 1, rnd);
    vector<pair<int, int>> V;
    auto ask = [&](int p) {
        cout << "? " << p << endl;
        int x, y; cin >> x >> y;
        return make_pair(x, y);
    };
    V.emplace_back(ask(st).first, st);
    for (int i = 1; i <= min(n, 1000); i++) {
        V.emplace_back(ask(perm[i]).first, perm[i]);
    }
    sort(V.begin(), V.end());
    if (V[0].first >= x) {
        cout << "! " << V[0].first << endl, exit(0);
    }
    int lst = 0, cur;
    for (int i = 0; i < V.size(); i++) {
        if (V[i].first == x) {
            cout << "! " << V[i].first << endl, exit(0);
        }
        if (V[i].first < x) lst = i, cur = V[i].second;
    }
    while (~cur) {
        auto p = ask(cur);
        if (p.first >= x) {
            cout << "! " << p.first << endl, exit(0);
        }
        cur = p.second;
    }
    cout << "! " << -1 << endl;
    return 0;
}