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
ifstream fin("input.in");
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
    int n, m; fin >> n >> m;
    vector<int> a(m), pmin(n), pmax(n, 0), prev(n, 0);
    for (auto& x : a) fin >> x;
    iota(all(pmin), 1);
    for (auto& x : a) pmin[x-1] = 1;
    fenwick<int> prefix(n), range(m);
    for (int j = 0; j < m; j++) {
        int x = a[j]-1;
        if (prev[x] == 0) {
            pmax[x] = max(pmax[x], x+1+prefix.query(x+1, n-1));
        } else {
            pmax[x] = max(pmax[x], range.query(prev[x], j-1)+1);
            range.update(prev[x]-1, -1);
        }
        range.update(j, 1);
        prev[x] = j+1;
        if (prefix.query(x, x) == 0)
            prefix.update(x, 1);
    }
    for (int x = 0; x < n; x++) {
        if (prev[x] == 0) {
            pmax[x] = max(pmax[x], x+1+prefix.query(x+1, n-1));
        } else {
            pmax[x] = max(pmax[x], range.query(prev[x], m-1)+1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << pmin[i] << " " << pmax[i] << "\n";
}