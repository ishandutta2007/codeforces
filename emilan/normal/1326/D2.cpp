#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

ll p1[1000000], p2[1000000];
const int m1 = 1e9 + 7, m2 = 1e9 + 9;

struct Hash {
    ll h1, h2;
    Hash(ll a, ll b) : h1(a), h2(b) {}
    Hash() : Hash(0, 0) {}
    void compute(char c, int p) {
        h1 = (h1 + (c - 'a' + 1) * p1[p]) % m1;
        h2 = (h2 + (c - 'a' + 1) * p2[p]) % m2;
    }
    Hash shift(int p) {
        return Hash(h1 * p1[p] % m1, h2 * p2[p] % m2);
    }
    Hash& operator+=(Hash o) {
        h1 = (h1 + o.h1) % m1;
        h2 = (h2 + o.h2) % m2;
        return *this;
    }
    Hash operator-(Hash o) {
        return Hash((h1 - o.h1 + m1) % m1, (h2 - o.h2 + m2) % m2);
    }
    bool operator==(Hash o) const {
        return h1 == o.h1 && h2 == o.h2;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    using u64 = uint64_t;
    u64 seed = chrono::steady_clock::now().time_since_epoch().count();

    ll b1 = ll(seed % m1);
    ll b2 = ll(seed % m1);

    p1[0] = p2[0] = 1;
    for (int i = 1; i < 1000000; i++) {
        p1[i] = p1[i - 1] * b1 % m1;
        p2[i] = p2[i - 1] * b2 % m2;
    }

    int tcs;
    cin >> tcs;
    while (tcs--) {
        string s;
        cin >> s;

        int l;
        for (l = 0; l < sz(s) / 2 && s[l] == s[sz(s) - l - 1]; l++);
        if (l == sz(s) / 2) {
            cout << s << '\n';
            continue;
        }

        string t(s.begin() + l, s.end() - l), r(rall(t));
        vt<Hash> pt(sz(t) + 1), pr(sz(t) + 1);
        rep(i, sz(t)) {
            pt[i + 1].compute(t[i], i);
            pr[i + 1].compute(r[i], i);
            pt[i + 1] += pt[i];
            pr[i + 1] += pr[i];
        }

        int al = l, ar = l + 1, hn = sz(t) / 2;
        for (int i = hn; i >= 0; i--) {
            if (i * 2 != sz(t)) {
                if (pt[i].shift((hn - i) * 2) ==
                        pr[hn * 2 - i] - pr[(hn - i) * 2]) {
                    al = l, ar = sz(s) - l - (hn - i) * 2;
                    break;
                } else if (pr[i].shift((hn - i) * 2) ==
                        pt[hn * 2 - i] - pt[(hn - i) * 2]) {
                    al = l + (hn - i) * 2, ar = l + sz(t);
                    break;
                }
            }

            if (pt[i].shift((hn - i) * 2 + 1) ==
                    pr[hn * 2 - i + 1] - pr[(hn - i) * 2 + 1]) {
                al = l, ar = sz(s) - l - (hn - i) * 2 - 1;
                break;
            } else if (pr[i].shift((hn - i) * 2 + 1) ==
                    pt[hn * 2 - i + 1] - pt[(hn - i) * 2 + 1]) {
                al = l + (hn - i) * 2 + 1, ar = l + sz(t);
                break;
            }
        }

        cout << string(s.begin(), s.begin() + l)
             << string(s.begin() + al, s.begin() + ar)
             << string(s.end() - l, s.end()) << '\n';
    }
}