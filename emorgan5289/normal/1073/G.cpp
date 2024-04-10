#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct suffixarray {

    // s = original string, a = suffix array
    // r = inverse suffix array (i.e. a[r[i]] = i)
    // lcp[i] = length of longest common prefix of a[i] and a[i+1]
    vector<int> s, a, r, lcp;

    // runs in O(nlogn) time.
    template<typename it>
    suffixarray(it first, it last) : s(first, last) {

        // construct a, r
        int n = s.size()+1, c = 1, j = 1, b;
        map<int, vector<int>> grp;
        vector<int> rc(n);
        r.resize(n); a.resize(n);
        for (int i = 0; i < n-1; i++)
            grp[s[i]].push_back(i);
        a[0] = n-1, r[n-1] = 0;
        for (auto& [_, v] : grp) {
            for (auto& i : v)
                r[i] = c, a[j++] = i;
            c++;
        }
        vector<vector<int>> cnt(n);
        for (int k = 1; k < 2*n; k <<= 1) {
            for (int i = 0; i < n; i++)
                cnt[r[b = (a[i]+2*n-k)%n]].push_back(b);
            c = -1, j = 0;
            for (auto& v : cnt) {
                for (int i = 0; i < v.size(); i++) {
                    if (i == 0 || r[(v[i]+k)%n] != r[(v[i-1]+k)%n]) c++;
                    rc[v[i]] = c, a[j++] = v[i];
                } v.clear();
            } swap(r, rc);
        }
        a.erase(a.begin()), r.erase(r.end()-1);

        // construct lcp
        lcp.resize(--n-1), c = 0;
        for (int i = 0; i < n; i++) {
            if (--r[i] == 0) continue;
            j = a[r[i]-1];
            while (max(i, j)+c < n && s[i+c] == s[j+c]) c++;
            lcp[r[i]-1] = c, c = max(0, c-1);
        }
    }

    suffixarray(string str) : suffixarray(str.begin(), str.end()) {}

    // returns a pair [l, r] such that all suffixes starting at
    // indices in the suffix array a[l..r] contain the input as a prefix,
    // runs in O(mlogn) time where m is the input size.
    template<typename it>
    pair<int, int> interval(it first, it last) const {
        auto cmp = [&](int p) {
            for (int i = 0; first+i != last; i++) {
                if (p+i >= s.size() || s[p+i] < first[i]) return -1;
                if (s[p+i] > first[i]) return 1;
            } return 0;
        };
        int m, l, x = 0, y = s.size();
        while (x < y)
            if (cmp(a[m = (x+y)/2]) == -1) x = m+1;
            else y = m;
        l = x, x = -1, y = s.size()-1;
        while (x < y)
            if (cmp(a[m = (x+y+1)/2]) == 1) y = m-1;
            else x = m;
        return {l, x};
    }

    pair<int, int> interval(string str) const {
        return interval(str.begin(), str.end());
    }
};

// Preferable to generalized range associative-function query due to a much smaller constant factor.

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    // runs in O(nlogn).
    rmq(vector<T>& data) {
        int n = data.size();
        int log2n = n == 0 ? 0 : ceil(log2(n));
        tree.assign(log2n+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= log2n; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = min(tree[i-1][j], tree[i-1][j+(1<<i-1)]);
    }

    // returns the minimum of the array on the interval [a..b] in O(1) time.
    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return min(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

struct st {
    ll r = 0;
    map<ll, ll, greater<>> m;
    void ins(ll x) { m[x]++; r += x; }
    void upd(ll x) {
        ll c = 0;
        while (!m.empty() && m.begin()->first > x) {
            c += m.begin()->second;
            r -= m.begin()->first*m.begin()->second;
            m.erase(m.begin());
        }
        m[x] += c; r += c*x;
    }
    void clr() { r = 0; m.clear(); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    suffixarray a(s);
    rmq r(a.lcp);
    vector<pair<ll, ll>> p;
    st q1, q2;
    while (q--) {
        ll k, l; cin >> k >> l;
        p.clear(), q1.clr(), q2.clr();
        for (ll i = 0; i < k+l; i++) {
            ll x; cin >> x;
            p.pb({a.r[x-1], i >= k ? 1 : 0});
        }
        sort(all(p));
        ll ans = 0;
        for (ll i = 0; i < k+l; i++) {
            auto [x, t] = p[i];
            if (t) q1.ins(n-a.a[x]), ans += q2.r;
            else q2.ins(n-a.a[x]), ans += q1.r;
            if (i != k+l-1 && x != p[i+1].first) {
                q1.upd(r.query(x, p[i+1].first-1));
                q2.upd(r.query(x, p[i+1].first-1));
            }
        }
        cout << ans << "\n";
    }
}