#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

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

auto now() {
    return chrono::steady_clock::now();
}

template<typename T>
void delta(T a, T b) {
    cout << chrono::duration_cast<chrono::milliseconds>(b-a).count() << "ms\n";
}

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
        auto cmp = [&](int _p) {
            for (int i = 0; first+i != last; i++) {
                if (_p+i >= s.size() || s[_p+i] < first[i]) return -1;
                if (s[_p+i] > first[i]) return 1;
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

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    rmq() {}

    // runs in O(nlogn).
    rmq(vector<T>& data) {
        int n = data.size();
        int h = n == 0 ? 0 : ceil(log2(n));
        tree.assign(h+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= h; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = min(tree[i-1][j], tree[i-1][j+(1<<(i-1))]);
    }

    // returns the minimum of the array on the interval [a..b] in O(1) time.
    inline T query(int a, int b) {
        int n = log2(b-a+1);
        return min(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

struct segtree {

    vector<int> a, b;
    vector<vector<int>> tree;
    int n;

    segtree() {}

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        map<int, int> seen;
        vector<int> pos(v.size());
        for (int i = v.size()-1; i >= 0; i--) {
            if (!seen.count(v[i])) pos[i] = inf;
            else pos[i] = seen[v[i]];
            seen[v[i]] = i;
        }

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i].pb(pos[i-n]);
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                merge(all(tree[2*i]), all(tree[2*i+1]), back_inserter(tree[i]));
            }
        }
    }

    int get(int i, int r) {
        // debug(tree[i].size());
        // int ans = 0;
        // for (auto& x : tree[i])
        //     if (x > r) ans++;
        // return ans;
        return tree[i].size()-(upper_bound(all(tree[i]), r)-tree[i].begin());
    }

    int query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return get(i, r);
        if (l > b[i] || r < a[i])
            return 0;
        return query(l, r, 2*i)+query(l, r, 2*i+1);
    }
};

const int N = 2e5+5;
string s;
vector<int> p, pr;
rmq<int> q;
segtree seg;
ll n, k, ans[N], ml[N], prec[N];

bool count(int i, int len) {
    int l = i, r = i;
    for (int x = 1<<20; x > 0; x /= 2) {
        if (l-x >= 0 && q.query(l-x, i-1) >= len) l -= x;
        if (r+x < p.size() && q.query(i, r+x-1) >= len) r += x;
    }
    return l <= prec[r];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string t; cin >> t; s += t+'$';
        while (p.size() < s.size()) p.pb(i);
    }
    suffixarray a(s);
    q = rmq(a.lcp);
    pr.resize(p.size());
    // auto t = now();
    for (int i = a.a.size()-1; i >= 0; i--) {
        pr[i] = p[a.a[i]];
        if (s[i] == '$') ml[i] = 0;
        else ml[i] = ml[i+1]+1;
    }
    seg = segtree(pr);
    for (int i = 0; i < a.a.size(); i++) {
        if (i > 0) prec[i] = prec[i-1]; 
        while (prec[i] < i && seg.query(prec[i]+1, i) >= k) prec[i]++;
    }
    // delta(t, now());
    for (int i = 0; i < a.a.size(); i++) {
        int l = 0, r = ml[a.a[i]];
        while (l < r) {
            int m = (l+r+1)/2;
            if (count(i, m)) l = m;
            else r = m-1;
        }
        ans[pr[i]] += l;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}