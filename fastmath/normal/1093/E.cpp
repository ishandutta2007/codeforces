#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int MAXN = 200001;

int n, q;
int a[MAXN], b[MAXN], ap[MAXN];
ordered_set f[MAXN];

void add(int i, int x) {
    for (; i < MAXN; i |= (i + 1)) {
        f[i].insert(x);
    }   
}   

void del(int i, int x) {
    for (; i < MAXN; i |= (i + 1)) {
        f[i].erase(x);
    }   
}   

int get(int i, int l, int r) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f[i].order_of_key(r + 1) - f[i].order_of_key(l);
    }   
    return ans;
}   

void read(int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
}
   
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    read(n, a); read(n, b);

    for (int i = 0; i < n; ++i) {
        ap[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        add(ap[b[i]], i);
    }   

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            --l1; --r1; --l2; --r2;
            cout << get(r1, l2, r2) - get(l1 - 1, l2, r2) << '\n';
        }    
        else {
            int p1, p2;
            cin >> p1 >> p2;
            --p1; --p2;
            del(ap[b[p1]], p1);
            del(ap[b[p2]], p2);
            swap(b[p1], b[p2]);
            add(ap[b[p1]], p1);
            add(ap[b[p2]], p2);
        }   
    }   

    return 0;
}