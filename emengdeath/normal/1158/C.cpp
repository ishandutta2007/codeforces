#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 3e6;
int T, n;
vector<int>g[N];
int id[N], d[N], du[N], from[N];
int ans[N];
void add(int x, int y){
    g[x].push_back(y);
    du[y] ++;
}
void build(int l, int r,int s) {
    if (l == r){
        id[l] = s;
        from[s] = l;
        return;
    }
    build(l, (l + r)/ 2, s + s);
    build((l + r)/ 2 + 1, r, s + s + 1);
    add(s, s + s);
    add(s, s + s + 1);
}
void ins(int l, int r,int s, int ll, int rr, int x) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr ){
        add(x, s);
        return;
    }
    ins(l, (l+r) / 2, s + s, ll, rr, x);
    ins((l+r) / 2 + 1, r, s + s + 1, ll, rr, x);
}
int main(){
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        build(1, n, 1);
        for (int i = 1; i <= n; i ++)
        {
            int x;
            scanf("%d", &x);
            if (x != -1){
                ins(1, n, 1, i + 1, x - 1, id[i]);
                if (x <= n)add(id[x], id[i]);
            }
        }
        int l = 0, r = 0;
        for (int i = 1; i <= n * 4; i ++)
            if (!du[i])
                d[++r] = i;
        int tot = n;
        while (l < r) {
            ++l;
            for (auto u:g[d[l]])
                if (!(--du[u]))
                    d[++r] = u;
            if (from[d[l]])
                ans[from[d[l]]] = tot--;
        }
        if (tot) printf("-1\n");
        else{
            for (int i = 1; i <= n ; i ++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        for (int i = 1;i <= n * 4; i ++)
            du[i] = 0, g[i].clear() ,from[i] = 0;
    }
    return 0;
}