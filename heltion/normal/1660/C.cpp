#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        vector<int> f(26), g(26, INT_MIN);
        for (char c : s) {
            vector<int> nf = f, ng = g;
            for (int i = 0; i < 26; i += 1)
                ng[c - 'a'] = max(f[i] + 1, ng[c - 'a']);
            nf[c - 'a'] = max(g[c - 'a'] + 1, nf[c - 'a']);
            f.swap(nf);
            g.swap(ng);
        }
        cout << s.size() - ranges::max(f) << "\n";
    }
    return 0;
}