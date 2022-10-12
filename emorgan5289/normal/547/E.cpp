#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct suffixarray {

    vector<int> s, a;

    // constructs a suffix array in O(nlogn) time, where K is the alphabet size.
    template<typename it>
    suffixarray(it first, it last) : s(first, last), a(last-first+1) {
        int n = s.size()+1, c = 1, j = 1, b;
        map<int, vector<int>> grp;
        vector<int> r(n), rc(n);
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
        } a.erase(a.begin());
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

struct segtree {

    struct node {
        vector<int> v;
    };

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size())
                    tree[i].v.pb(v[i-n]);
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                merge(all(tree[2*i].v), all(tree[2*i+1].v), back_inserter(tree[i].v));
            }
        }
    }

    int get(int i, int k) {
        return lower_bound(all(tree[i].v), k)-tree[i].v.begin();
    }

    int query(int l, int r, int k, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return get(i, k);
        if (l > b[i] || r < a[i])
            return 0;
        return query(l, r, k, 2*i) + query(l, r, k, 2*i+1);
    }
};

const int N = 5e5+5;
int in[N], out[N], res[N];
vector<array<int, 3>> qry[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = "";
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string t; cin >> t; s += '$', s += t;
        in[i] = s.size()-t.size(), out[i] = s.size()-1;
    }
    suffixarray a(s);
    segtree seg(a.a);
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k; l--, r--, k--;
        qry[k].pb({in[l], out[r]-out[k]+in[k], i});
    }
    for (int k = 0; k < n; k++) {
        string t = s.substr(in[k], out[k]-in[k]+1);
        auto [l, r] = a.interval(t);
        for (auto& [x, y, i] : qry[k]) {
            res[i] = seg.query(l, r, y+1) - seg.query(l, r, x);
        }
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}