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

using i128 = __int128_t;

istream& operator>>(istream& o, i128& i) {
    string s;
    auto& tmp = o >> s;
    i = 0;
    for (char c : s) i = 10*i + c-'0';
    return tmp;
}

string to_string(i128 i) {
    if (i == 0) return "0";
    string s;
    bool neg = i < 0;
    if (neg) i = -i;
    for (; i; i /= 10) s += '0'+i%10;
    if (neg) s += '-';
    reverse(all(s));
    return s;
}

ostream& operator<<(ostream& o, i128 i) {
    return o << to_string(i);
}

i128 gcd_i128(i128 a, i128 b) {
    while (b != 0) {
        auto t = b;
        b = a%b, a = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<i128> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        // for (int i = 0; i < n; i++)
        //     cout << a[i] << " \n"[i == n-1];
        // for (int i = 0; i < m; i++)
        //     cout << b[i] << " \n"[i == m-1];
        // cout << "\n";

        vector<i128> ab(n+m);
        vector<map<i128, int>> af(n), bf(m);

        for (int i = 0; i < n+m; i++)
            ab[i] = i < n ? a[i] : b[i-n];

        // turn af[i], bf[i] into map of "prime" factors of ab[i] -> freq of factor in ab[i]
        for (int i = 0; i < n+m; i++) {
            priority_queue<i128> s;
            s.push(ab[i]);
            while (!s.empty()) {
                auto x = s.top(); s.pop();
                bool found = 0;
                for (int j = 0; j < n+m; j++) {
                    auto g = gcd_i128(x, ab[j]);
                    if (g != 1 && g != x) {
                        s.push(g), s.push(x/g);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    (i < n ? af[i] : bf[i-n])[x]++;
            }
        }

        // for (int i = 0; i < n; i++)
        //     for (auto& [x, fx] : af[i])
        //         cout << i << " " << x << " " << fx << "\n";
        // cout << "\n";

        // for (int i = 0; i < m; i++)
        //     for (auto& [x, fx] : bf[i])
        //         cout << i << " " << x << " " << fx << "\n";
        // cout << "\n";

        // l[i] = list of frequencies at which prime i appears per element in a
        map<i128, multiset<i128>> l, r;
        for (int i = 0; i < n; i++)
            for (auto& [x, fx] : af[i])
                l[x].insert(fx);
        for (int i = 0; i < m; i++)
            for (auto& [x, fx] : bf[i])
                r[x].insert(fx);

        vector<int> av(n, 1), bv(m, 1);
        while (1) {
            bool found = 0;
            for (int i = 0; i < n; i++)
                if (av[i]) {
                    bool ok = 1;
                    for (auto& [x, fx] : af[i])
                        if (r[x].empty() || *--r[x].end() < fx) {
                            debug("a", i, (ll)x, fx);
                            ok = 0;
                            break;
                        }
                    if (!ok) {
                        av[i] = 0;
                        for (auto& [x, fx] : af[i])
                            l[x].erase(l[x].find(fx));
                        found = 1;
                    }
                }
            for (int i = 0; i < m; i++)
                if (bv[i]) {
                    bool ok = 1;
                    for (auto& [x, fx] : bf[i])
                        if (l[x].empty() || *--l[x].end() < fx) {
                            debug("b", i, (ll)x, fx);
                            ok = 0;
                            break;
                        }
                    if (!ok) {
                        bv[i] = 0;
                        for (auto& [x, fx] : bf[i])
                            r[x].erase(r[x].find(fx));
                        found = 1;
                    }
                }
            if (!found) break;
        }

        int a_count = 0, b_count = 0;
        for (int i = 0; i < n; i++)
            if (av[i]) a_count++;
        for (int i = 0; i < m; i++)
            if (bv[i]) b_count++;

        if (a_count && b_count) {
            cout << "YES\n" << a_count << " " << b_count << "\n";
            for (int i = 0; i < n; i++)
                if (av[i]) cout << a[i] << " ";
            cout << "\n";
            for (int i = 0; i < m; i++)
                if (bv[i]) cout << b[i] << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}