#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        int k;
        cin >> k;
        vector<int> sp(26);
        for (int i = 0; i < k; i += 1) {
            char c;
            cin >> c;
            sp[c - 'a'] = 1;
        }
        vector<int> t;
        for (char c : s)
            t.push_back(sp[c - 'a']);
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i += 1) {
            if (not i or t[i] != t[i - 1])
                vp.emplace_back(t[i], 1);
            else vp.back().second += 1;
        }
        if (vp.back().first == 0) vp.pop_back();
        int ans = 0;
        while (vp.size() > 1 or (vp[0].first and vp[0].second > 1)) {
            vector<pair<int, int>> wp;
            for (int i = 0; i < vp.size(); i += 1) {
                if (i) assert(vp[i].first != vp[i - 1].first);
                if (vp[i].first == 1) {
                    if (not wp.empty() and wp.back().first == 1)
                        wp.back().second += 1;
                    else wp.emplace_back(1, 1);
                }
                else if (vp[i].second > 1)
                    wp.emplace_back(0, vp[i].second - 1);
            }
            vp.swap(wp);
            ans += 1;
        }
        cout << ans << "\n";
    }
}