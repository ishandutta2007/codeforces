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

template<typename it1, typename it2>
void compress(it1 first, it1 last, it2 result) {
    typedef typename remove_reference<decltype(*first)>::type T;
    map<T, vector<it2>> m;
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [x, v] : m) {
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
        tree.assign(length+1, 0);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] = max(tree[i], val);
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out = max(out, tree[i]);
            i -= i & -i;
        }
        return out;
    }
};

const ll N = 1e5+5;
ll px[N], py[N];
array<ll, 3> p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char buf;
    ll n, a, b, c, d; cin >> n >> a >> buf >> b >> c >> buf >> d;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        px[i] = x*c-y*d, py[i] = x*a-y*b;
    }
    px[n] = py[n] = 0;
    compress(px, px+n+1, px);
    compress(py, py+n+1, py);
    for (int i = 0; i < n+1; i++)
        p[i] = {px[i], py[i], i};
    sort(p, p+n+1, greater<>());
    fenwick<int> f(n);
    for (int i = 0; i < n+1; i++) {
        if (p[i][2] == n)
            cout << f.prefix(p[i][1]-1) << "\n";
        f.update(p[i][1], f.prefix(p[i][1]-1)+1);
    }
}