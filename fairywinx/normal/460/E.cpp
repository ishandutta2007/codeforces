#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

bool check(pair<int, int> a, int r) {
    if (a.first * a.first + a.second * a.second <= r * r)
        return true;
    else
        return false;
}

void rek(int ind, vector<pair<int, int>> c, vector<pair<int, int>> &ans, vector<pair<int, int>> &now, int &val, int n) {
    if ((int) now.size() == n) {
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                tmp += (now[i].first - now[j].first) * (now[i].first - now[j].first) + (now[i].second - now[j].second) * (now[i].second - now[j].second);
            }
        }
        if (tmp > val) {
            val = tmp;
            ans = now;
        }
        return;
    }
    if (ind == (int) c.size())
        return;
    now.emplace_back(c[ind]);
    rek(ind, c, ans, now, val, n);
    now.pop_back();
    rek(ind + 1, c, ans, now, val, n);
}

bool good(pair<int, int> a, int r) {
    if (!check(a, r))
        return false;
    int mx[4] = {0, 0, 1, -1};
    int my[4] = {1, -1, 0, 0};
    bool find = false;
    for (int k = 0; k < 4; ++k) {
        if (!check({a.first + mx[k], a.second + my[k]}, r))
            find = true;
    }
    return find;
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> c;
    int mx[4] = {0, 0, 1, -1};
    int my[4] = {1, -1, 0, 0};
    for (int i = -33; i < 33; ++i) {
        for (int j = -33; j < 33; ++j) {
            if (!good({i, j}, r))
                continue;
            c.emplace_back(i, j);
        }
    }
    sort(all(c), [] (const pair<int, int> a, const pair<int, int> b) {
        return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
    });
    c.resize(min((int) c.size(), 20));
    // for (auto i : c)
    //     cout << i.first << ' ' << i.second << '\n';
    vector<pair<int, int>> ans;
    vector<pair<int, int>> now;
    int val = 0;
    rek(0, c, ans, now, val, n);
    cout << val << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';
}