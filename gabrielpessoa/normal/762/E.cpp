#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree < pair<int, int> ,  null_type ,  less<pair<int, int>> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

ordered_set s[ms];
int x[ms], r[ms], f[ms];
pair<int, int> ord[ms];

main() {
    int n, lim;
    scanf("%d%d", &n, &lim);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &x[i], &r[i], &f[i]);
        ord[i] = {-r[i], i};
    }
    sort(ord, ord+n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int k = ord[i].second;
        for(int j = max(0, f[k] - lim); j <= f[k] + lim; j++) {
            long long qnt = s[j].order_of_key(make_pair(r[k] + x[k], inf)) - s[j].order_of_key(make_pair(x[k] - r[k], -1));
            ans += qnt; 
        }
        s[f[k]].insert(make_pair(x[k], k));
    }
    cout << ans << '\n';
}