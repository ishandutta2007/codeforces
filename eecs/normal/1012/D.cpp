#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
string s, t;
vector<pair<int, int>> ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;
    auto get = [&](string s) {
        vector<pair<char, int>> V;
        for (int i = 0, j; i < s.size(); i = j) {
            for (j = i; j < s.size() && s[i] == s[j]; j++);
            V.emplace_back(s[i], j - i);
        }
        reverse(V.begin(), V.end());
        return V;
    };
    auto x = get(s), y = get(t);
    bool flag = 0;
    auto append = [&](vector<pair<char, int>> &V, pair<char, int> p) {
        if (!V.empty() && V.back().first == p.first) V.back().second += p.second;
        else V.push_back(p);
    };
    auto query = [&](int cntx, int cnty) {
        vector<pair<char, int>> X, Y;
        while (cntx--) X.push_back(x.back()), x.pop_back();
        while (cnty--) Y.push_back(y.back()), y.pop_back();
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        int lenx = 0, leny = 0;
        for (auto &p : X) lenx += p.second;
        for (auto &p : Y) leny += p.second;
        if (flag) swap(lenx, leny);
        ans.emplace_back(lenx, leny);
        for (auto &p : X) append(y, p);
        for (auto &p : Y) append(x, p);
    };
    while (x.size() ^ 1 || y.size() ^ 1) {
        int la = x.size(), lb = y.size();
        if (la < lb) swap(la, lb), swap(x, y), flag ^= 1;
        char a = x.back().first, b = y.back().first;
        if (a != b) {
            query(lb > 2 || la <= 3 ? 1 : 3, 1);
        } else {
            if (lb == 1) query(la <= 3 ? 1 : 3, 0);
            else if (lb == 2) query(la == 2 ? 1 : 2, la == 2 ? 0 : 1);
            else query(3, 2);
        }
    }
    cout << ans.size() << '\n';
    for (auto &p : ans) {
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}