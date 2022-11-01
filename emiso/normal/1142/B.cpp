#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, q, p[MN], ip[MN], a[MN], id[MN], vt[MN], ans[MN];
vector<int> occ[MN];

int rmq[MN][20];
void build() {
    for(int i = 0; i < m; i++)
        rmq[i][0] = ans[i];

    for(int j = 1; (1 << j) <= m; j++)
        for(int i = 0; i + (1 << j) <= m; i++)
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1 << (j-1))][j-1]);
}

int query(int a, int b) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);
    return min(rmq[a][lg], rmq[b -(1 << lg)+1][lg]);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        ip[p[i]] = i;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        occ[a[i]].push_back(i);
        ans[i] = INT_MAX;
    }

    for(int i = 0; i < m; i++) {
        if(a[i] == p[0]) vt[i] = i;
        else {
            int idx = ip[a[i]];
            vector<int> &v = occ[p[idx-1]];
            int pos = lower_bound(v.begin(), v.end(), i) - v.begin();
            if(pos == 0) vt[i] = -1;
            else vt[i] = vt[v[pos-1]];
        }
    }
    for(int i = m-1; i >= 0; i--) {
        if(a[i] == p[n-1]) id[i] = i;
        else {
            int idx = ip[a[i]];
            vector<int> &v = occ[p[idx+1]];
            int pos = lower_bound(v.begin(), v.end(), i) - v.begin();
            if(pos == v.size()) id[i] = -1;
            else id[i] = id[v[pos]];
        }
    }

    for(int i = 0; i < m; i++) {
        if(id[i] == -1) continue;
        int idx = ip[a[i]];
        if(idx == 0) ans[i] = id[i];
        else {
            vector<int> &v = occ[p[idx-1]];
            int l = 0, r = v.size(), m;
            while(l < r) {
                m = (l + r)/2;
                if(id[i] < vt[v[m]]) r = m;
                else l = m + 1;
            }
            if(l < v.size()) ans[i] = v[l];
        }
    }

    build();
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        if(query(l, r) <= r) printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}