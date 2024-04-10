#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
vector<pair<int, int>> vp[maxn], ch[maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 2; i < maxn; i += 1)
        if (vp[i].empty())
            for (int j = i; j < maxn; j += i) {
                vp[j].emplace_back(i, 0);
                for (int k = j; k % i == 0; k /= i) vp[j].back().second += 1;
            }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    string s;
    cin >> s;
    vector<vector<int>> L(n), R(n);
    for (int i = 0; i < n; i += 1)
        for (auto [p, c] : vp[a[i]])
            ch[p].emplace_back(i, s[i] == '*' ? c : -c);
    for (int i = 2; i < maxn; i += 1) if (ch[i].size()) {
        int m = ch[i].size();
        vector<int> sum(m);
        for (int j = 0; j < m; j += 1) {
            sum[j] = ch[i][j].second;
            if (j) sum[j] += sum[j - 1];
        }
        vector<pair<int, int>> st = {{sum[m - 1], m - 1}};
        for (int j = m - 1; j >= 0; j -= 1) {
            int p = j ? sum[j - 1] : 0;
            while (not st.empty() and st.back().first >= p) st.pop_back();
            st.emplace_back(p, j - 1);
            int tl = (int)st.size() - 2;
            if (tl != -1) {
                int l = j ? ch[i][j - 1].first + 1 : 0;
                int r = ch[i][j].first;
                int x = ch[i][st[tl].second].first - 1;
                L[l].push_back(x);
                R[r].push_back(x);
            }
        }
    }
    LL ans = 0;
    multiset<int> ms;
    for (int i = 0; i < n; i += 1) {
        for (int l : L[i]) ms.insert(l);
        if (ms.empty()) ans += n - i;
        else ans += *ms.begin() - i + 1;
        for (int r : R[i]) ms.erase(ms.find(r));
    }
    cout << ans << "\n";
    return 0;
}