#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(ll n) { a.resize(n + 1); }
    fenwick_tree(vector<T> &vec) : a(vec) {
        for(int i = 1; i+(i&-i) < (int)a.size(); i++) a[i+(i&-i)] += a[i];
    }
    void update(int idx, T delta) {
        for(; idx < (int)a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

ll t = 1, n, m, ans, a[MN];

int main() {
scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    vector<fenwick_tree<int>> bits;
    for(int i = 0; i < n * m; i++) {
        scanf("%lld", &a[i]);
        bits.push_back(fenwick_tree<int>(m + 1));
    }

    vector<int> ord(n*m), rev(n*m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if(a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    for(int i = 0; i < n * m; i += m) {
        sort(ord.begin() + i, ord.begin() + i + m, [&](int i, int j) {
            if(a[i] != a[j]) return a[i] < a[j];
            return i > j;
        });
    }
    
    for(int i = 0; i < n * m; i++)
        rev[ord[i]] = i;

    for(int k = 0; k < n * m; k++) {
        int i = rev[k];
        int row = i / m, col = i % m + 1;
        ans += bits[row].query(col);
        bits[row].update(col, 1);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}