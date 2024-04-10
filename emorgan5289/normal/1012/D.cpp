#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

vector<array<ll, 2>> solve(string s, string t, int p1, int p2, bool swp) {
    vector<array<ll, 2>> ans;

    int ps = 0, pt = 0;
    for (int i = 0; i+1 < s.size(); i++)
        if (s[i] != s[i+1]) ps++;
    if (s.back() != 'a') ps++;
    for (int i = 0; i+1 < t.size(); i++)
        if (t[i] != t[i+1]) pt++;
    if (t.back() != 'b') pt++;
    debug(ps, pt);

    if (ps < pt) {
        int i = 0, j = 0;
        for (int k = 0; k < (pt-ps+p1)/2; k++) {
            while (j+1 < t.size() && t[j] == t[j+1]) j++;
            if (j < t.size()) j++;
        }
        for (int k = 0; k < p2; k++) {
            while (i+1 < s.size() && s[i] == s[i+1]) i++;
            if (i < s.size()) i++;
        }
        if (j != 0 || i != 0) {
            ans.pb({i, j});
        }
        string p = s.substr(0, i)+t.substr(j, t.size());
        string q = t.substr(0, j)+s.substr(i, s.size());
        t = p, s = q;
    }

    if (pt < ps) {
        int i = 0, j = 0;
        for (int k = 0; k < (ps-pt+p1)/2; k++) {
            while (i+1 < s.size() && s[i] == s[i+1]) i++;
            if (i < s.size()) i++;
        }
        for (int k = 0; k < p2; k++) {
            while (j+1 < t.size() && t[j] == t[j+1]) j++;
            if (j < t.size()) j++;
        }
        if (i != 0 || j != 0) {
            ans.pb({i, j});
        }
        string p = s.substr(0, i)+t.substr(j, t.size());
        string q = t.substr(0, j)+s.substr(i, s.size());
        t = p, s = q;
    }

    ps = 0, pt = 0;
    for (int i = 0; i+1 < s.size(); i++)
        if (s[i] != s[i+1]) ps++;
    if (s.back() != 'a') ps++;
    for (int i = 0; i+1 < t.size(); i++)
        if (t[i] != t[i+1]) pt++;
    if (t.back() != 'b') pt++;
    debug(ps, pt);

    int i = s.size(), j = t.size();
    bool c = 0;
    while (i > 0 || j > 0) {
        if (!c) {
            while (i > 0 && s[i-1] != 'a') i--;
            while (j > 0 && t[j-1] != 'b') j--;
            ans.pb({i, j});
        } else {
            while (i > 0 && s[i-1] != 'b') i--;
            while (j > 0 && t[j-1] != 'a') j--;
            ans.pb({j, i});
        }
        debug(i, j, s, t);
        c = !c;
    }
    ans.pop_back();
    debug(s, t, ans);
    if (swp) {
        for (auto& [p, q] : ans) swap(p, q);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t; cin >> s >> t;
    vector<vector<array<ll, 2>>> ans;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            ans.pb(solve(s, t, i, j, 0));
            ans.pb(solve(t, s, i, j, 1));
        }
    int k = 0;
    for (int i = 1; i < ans.size(); i++)
        if (ans[i].size() < ans[k].size()) k = i;

    cout << ans[k].size() << "\n";
    for (auto& [i, j] : ans[k])
        cout << i << " " << j << "\n";
}