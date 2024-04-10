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
#define cin fin
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
            tree[i] += val;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out += tree[i];
            i -= i & -i;
        }
        return out;
    }

    // sum over a..b, inclusive
    T query(int a, int b) {
        return prefix(b)-prefix(a-1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ull n; fin >> n;
    vector<ull> q(n);
    for (ull i = 0; i < n; i++) {
        ull a; fin >> a;
        q[a-1] = i;
    }
    ull inv = 0, mid = q[0];
    fenwick<ull> f(n), g(n);
    set<int> s;

    for (ull i = 0; i < n; i++) {
        ull x = q[i];
        inv += i-f.prefix(x-1);
        f.update(x, 1);
        g.update(x, x);

        s.insert(x);
        if (f.prefix(mid-1) < i/2)
            mid = *s.upper_bound(mid);
        if (f.prefix(mid-1) > i/2)
            mid = *(--s.lower_bound(mid));

        ull lsum = g.query(0, mid-1);
        ull usum = g.query(mid+1, n-1);
        ull lcnt = i/2;
        ull ucnt = i/2 + (i&1);

        // (m - x1 - 3) + (m - x2 - 2) + (m - x3 - 1)

        cout << (inv - mid*(i&1) - lsum - lcnt*(lcnt+1)/2 + usum - ucnt*(ucnt+1)/2) << " ";
    }
}