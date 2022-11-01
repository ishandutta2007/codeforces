#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) { a.resize(n + 1); }
    void update(int idx, T delta) {
        ++idx;
        for(; idx < (int)a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        ++idx;
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

ll t = 1, n, ans, a[MN];
char s[MN]; string str, pat;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    scanf("%s", s); str = s;
    scanf("%s", s); pat = s;

    fenwick_tree<int> bit(n);
    
    vector<int> ptr(26);
    vector<vector<int>> occ(26);

    for (int i = 0; i < n; i++) {
        occ[str[i]-'a'].push_back(i);
    }
    
    ans = LLONG_MAX;
    ll cur = 0;

    for (int i = 0; i < n; i++) {
        int c = pat[i] - 'a';
        for (int j = 0; j < c; j++) {
            while (ptr[j] < occ[j].size() && occ[j][ptr[j]] + i - bit.query(occ[j][ptr[j]]) < i) {
                ptr[j]++;
            }
            if (ptr[j] == occ[j].size()) continue;
            int pos = occ[j][ptr[j]] + i - bit.query(occ[j][ptr[j]]);
            ans = min(ans, cur + pos - i);
        }

        while (ptr[c] < occ[c].size() && occ[c][ptr[c]] + i - bit.query(occ[c][ptr[c]]) < i) {
            ptr[c]++;
        }
        if (ptr[c] == occ[c].size()) break;
        int pos = occ[c][ptr[c]] + i - bit.query(occ[c][ptr[c]]);
        cur += (pos - i);
        bit.update(occ[c][ptr[c]], 1);
        ptr[c]++;
    }

    if (ans < LLONG_MAX) printf("%lld\n", ans);
    else printf("-1\n");
    if(--t) goto st;
    return 0;
}