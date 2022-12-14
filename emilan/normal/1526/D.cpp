#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll inv(vector<int> &v) {
    int n = v.size();
    if (n <= 1) return 0;

    vector<int> a(v.begin(), v.begin() + n / 2);
    vector<int> b(v.begin() + n / 2, v.end());

    ll ans = 0;
    ans += inv(a);
    ans += inv(b);

    for (int i = 0, p = 0, q = 0; i < n; i++) {
        if (q == (n + 1) / 2 || (p != n / 2 && a[p] <= b[q])) {
            v[i] = a[p++];
        } else {
            ans += n / 2 - p;
            v[i] = b[q++];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int n = s.size();

        string m("ANOT"), best(m);
        ll max_inv = -1;
        do {
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) {
                    if (s[i] == m[j]) a[i] = j;
                }
            }

            ll inv_cnt = inv(a);
            if (inv_cnt > max_inv) {
                max_inv = inv_cnt;
                best = m;
            }
        } while (next_permutation(m.begin(), m.end()));

        map<char, int> mp;
        for (int i = 0; i < 4; i++) mp[best[i]] = i;

        sort(s.begin(), s.end(), [&](char x, char y) {
            return mp[x] < mp[y];
        });

        cout << s << '\n';
    }
}