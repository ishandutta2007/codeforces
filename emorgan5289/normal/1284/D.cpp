#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#endif

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int s) {
        length = s+1;
        tree = vector<T>(length+1);
    }

    fenwick(vector<T>& v) {
        length = v.size()+1;
        tree = vector<T>(length+1);
        for (int i = 0; i < v.size(); i++)
            update(i, v[i]);
    }

    // insert val at index i
    // to remove, just insert with negative val
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] ^= val;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out ^= tree[i];
            i -= i & -i;
        }
        return out;
    }

    // sum over a..b, inclusive
    T query(int a, int b) {
        return prefix(b)^prefix(a-1);
    }
};

template<typename T>
vector<int> compress(vector<T>& A) {

    vector<pair<int, int>> ordering(A.size());
    vector<int> out(A.size());
    for (int i = 0; i < A.size(); i++)
        ordering[i] = {A[i], i};

    sort(ordering.begin(), ordering.end());

    int offset = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i > 0 && ordering[i].first == ordering[i-1].first) offset++;
        out[ordering[i].second] = i-offset;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<int> a(2*n), b(2*n);
    vector<ull> ha(n, 0), hb(n, 0); hash<string> h;
    for (int i = 0; i < n; i++) {
        int p, q, r, s; fin >> p >> q >> r >> s;
        a[2*i] = p; a[2*i+1] = q;
        b[2*i] = r; b[2*i+1] = s;
    }
    a = compress(a); b = compress(b);
    fenwick<ull> fa(2*n), fb(2*n);
    for (int i = 0; i < n; i++) {
        int p = a[2*i], q = a[2*i+1];
        int r = b[2*i], s = b[2*i+1];
        ull hsh = h(to_string(i));
        fa.update(q, hsh); fb.update(s, hsh);
        debug(q, hsh);
    }
    for (int i = 0; i < n; i++) {
        int p = a[2*i], q = a[2*i+1];
        int r = b[2*i], s = b[2*i+1];
        if (p > 0) ha[i] ^= fa.query(0, p-1);
        if (r > 0) hb[i] ^= fb.query(0, r-1);
    }
    fill(all(fa.tree), 0); fill(all(fb.tree), 0);
    for (int i = 0; i < n; i++) {
        int p = a[2*i], q = a[2*i+1];
        int r = b[2*i], s = b[2*i+1];
        ull hsh = h(to_string(i));
        fa.update(p, hsh); fb.update(r, hsh);
        debug(p, hsh);
    }
    debug(ha); debug(hb);
    debug(fa.tree); debug(fb.tree);
    for (int i = 0; i < n; i++) {
        int p = a[2*i], q = a[2*i+1];
        int r = b[2*i], s = b[2*i+1];
        if (q < 2*n) ha[i] ^= fa.query(q+1, 2*n-1);
        if (s < 2*n) hb[i] ^= fb.query(s+1, 2*n-1);
    }
    debug(a); debug(b);
    debug(ha); debug(hb);
    for (int i = 0; i < n; i++)
        if (ha[i] != hb[i]) {
            cout << "NO\n"; return 0;
        }
    cout << "YES\n";
}