#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct suffixarray {

    vector<ll> s, a;

    // constructs a suffix array in O(nlogn) time, where K is the alphabet size.
    template<typename it>
    suffixarray(it first, it last) : s(first, last), a(last-first+1) {
        ll n = s.size()+1, c = 1, j = 1, b;
        map<ll, vector<ll>> grp;
        vector<ll> r(n), rc(n);
        for (ll i = 0; i < n-1; i++)
            grp[s[i]].push_back(i);
        a[0] = n-1, r[n-1] = 0;
        for (auto& [_, v] : grp) {
            for (auto& i : v)
                r[i] = c, a[j++] = i;
            c++;
        }
        vector<vector<ll>> cnt(n);
        for (ll k = 1; k < 2*n; k <<= 1) {
            for (ll i = 0; i < n; i++)
                cnt[r[b = (a[i]+2*n-k)%n]].push_back(b);
            c = -1, j = 0;
            for (auto& v : cnt) {
                for (ll i = 0; i < v.size(); i++) {
                    if (i == 0 || r[(v[i]+k)%n] != r[(v[i-1]+k)%n]) c++;
                    rc[v[i]] = c, a[j++] = v[i];
                }
                v.clear();
            }
            swap(r, rc);
        }
        a.erase(a.begin());
    }

    suffixarray(string str) : suffixarray(str.begin(), str.end()) {}

    // returns a pair [l, r] such that all suffixes starting at
    // indices in the suffix array a[l..r] contain the input as a prefix,
    // runs in O(mlogn) time where m is the input size.
    template<typename it>
    pair<ll, ll> llerval(it first, it last) const {
        auto cmp = [&](ll p) {
            for (ll i = 0; first+i != last; i++) {
                if (p+i >= s.size() || s[p+i] < first[i]) return -1;
                if (s[p+i] > first[i]) return 1;
            }
            return 0;
        };
        ll l, x = 0, y = s.size();
        while (x < y) {
            ll m = (x+y)/2;
            if (cmp(a[m]) == -1) x = m+1;
            else y = m;
        }
        l = x, x = -1, y = s.size()-1;
        while (x < y) {
            ll m = (x+y+1)/2;
            if (cmp(a[m]) == 1) y = m-1;
            else x = m;
        }
        return {l, x};
    }

    pair<ll, ll> llerval(string str) const {
        return llerval(str.begin(), str.end());
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string t; cin >> t;
    suffixarray a(t);
    reverse(all(t));
    suffixarray b(t);
    ll n, m = t.size(); cin >> n;
    vector<ll> p1(m), p2(m);
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        auto [l, r] = a.llerval(s);
        if (l <= r) {
            if (l < m) p1[l]++;
            if (r < m-1) p1[r+1]--;
        }
        reverse(all(s));
        tie(l, r) = b.llerval(s);
        if (l <= r) {
            if (l < m) p2[l]++;
            if (r < m-1) p2[r+1]--;
        }
    }
    for (ll i = 1; i < m; i++)
        p1[i] += p1[i-1], p2[i] += p2[i-1];
    vector<ll> x1(m), x2(m);
    for (ll i = 0; i < m; i++)
        x1[a.a[i]] = p1[i], x2[b.a[i]] = p2[i];
    reverse(all(x2));
    ll out = 0;
    for (ll i = 1; i < m; i++)
        out += x1[i]*x2[i-1];
    cout << out << "\n";
}