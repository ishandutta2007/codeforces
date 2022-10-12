#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e16+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// Transform the contents of [first, last) into elements of [0..N],
// while preserving the relative ordering/equality of the data.
// Runs in O(nlogn).

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename remove_reference<decltype(*first)>::type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int size) {
        length = size+1;
        tree.assign(length+1, inf_ll);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            cmin(tree[i], val);
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = inf_ll;
        while (i > 0) {
            cmin(out, tree[i]);
            i -= i & -i;
        }
        return out;
    }
};

const int N = 2e5+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    multiset<array<ll, 3>> m;
    map<ll, ll> mb;
    ll v = 0, ans = 0;
    vector<ll> ta(n), tb(n), ab, cb(2*n);
    for (int i = 0; i < n; i++)
        cin >> ta[i];
    for (int i = 0; i < n; i++)
        cin >> tb[i];
    for (int i = 0; i < n; i++) {
        ll a = ta[i], b = tb[i];
        v += abs(a-b);
        // debug(abs(a-b));
        m.insert({a, b, 0});
        m.insert({b, a, 1});
        ab.pb(a), ab.pb(b);
    }
    debug("fill");
    fenwick<ll> s1(2*n), s2(2*n);
    debug("compress");
    compress(all(ab), cb.begin());
    debug("fill map");
    for (int i = 0; i < 2*n; i++)
        mb[ab[i]] = cb[i];
    // debug(mb);
    debug("pass 1");
    for (auto& [a, b, t] : m) {
        ll i = mb[b];
        if (t == 0) {
            s1.update(i, -abs(a-b)-b-a);
            s2.update(2*n-1-i, -abs(a-b)+b-a);
            // debug(a, b, i);
        } else {
            cmin(ans, s1.prefix(i)-abs(a-b)+b+a);
            // debug(a, b, i, s1.min(0, i), ans);
            cmin(ans, s2.prefix(2*n-1-i)-abs(a-b)-b+a);
            // debug(a, b, i, s2.min(i, N-1), ans);
        }
    }
    debug("fill map");
    m.clear();
    for (int i = 0; i < n; i++) {
        ll a = ta[i], b = tb[i];
        m.insert({a, b, 1});
        m.insert({b, a, 0});
    }
    debug("fill");
    s1 = fenwick<ll>(2*n), s2 = fenwick<ll>(2*n);
    debug("pass 2");
    int j = 0;
    for (auto& [a, b, t] : m) {
        ll i = mb[b];
        // debug(i);
        if (t == 0) {
            // debug(s1.get(i));
            s1.update(i, -abs(a-b)-b-a);
            s2.update(2*n-1-i, -abs(a-b)+b-a);
            // debug(s1.get(i));
            // debug(a, b, i);
        } else {
            cmin(ans, s1.prefix(i)-abs(a-b)+b+a);
            // debug(a, b, i, s1.min(0, i), ans);
            cmin(ans, s2.prefix(2*n-1-i)-abs(a-b)-b+a);
            // debug(a, b, i, s2.min(i, N-1), ans);
        }
        // if (j++%1000 == 0) debug(j);
    }
    debug(ans, v);
    cout << ans+v << "\n";
}