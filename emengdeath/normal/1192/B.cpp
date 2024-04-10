#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <cstring>
using namespace std;
namespace Dynamic_Diameter//
{
    const int N = 2e5 + 1; //
    struct node{
        long long a, b, ab, bc, abc, tag;
    }f[N * 4];
    int dfnl[N], dfnr[N];
    long long w[N];
    int n, tot, etot;
    vector<pair<int, int> > g[N];
    void add_edge(int x, int y, long long v) {
        g[x].push_back(make_pair(y, ++etot));
        g[y].push_back(make_pair(x, etot));
        w[etot] = v;
    }
    void dfs(int x, int fa){
        for (auto u:g[x])
            if (u.first != fa)
            {
                dfnl[u.second] = ++ tot;
                dfs(u.first, x);
                dfnr[u.second] = ++ tot;
            }
    }
    void update(int s, long long v) {
        f[s].a += v;
        f[s].b += v;
        f[s].tag += v;
        f[s].ab -= v;
        f[s].bc -= v;
    }
    void down(int s) {
        update(s + s, f[s].tag);
        update(s + s + 1, f[s].tag);
        f[s].tag = 0;
    }
    void combine(node& a, node b, node c){
        a.a = max(b.a, c.a);
        a.b = min(b.b, c.b);
        a.ab = max({b.ab, c.ab, b.a - 2 * c.b});
        a.bc = max({b.bc, c.bc, c.a - 2 * b.b});
        a.abc = max({b.abc, c.abc, b.ab + c.a, c.bc + b.a});
    }
    void add(int l, int r, int s, int ll, int rr, long long v) {
        if (r < ll || rr < l) {
            return;
        }
        if (ll <=l && r <= rr) {
            update(s, v);
            return;
        }
        down(s);
        add(l, (l + r) / 2, s + s ,ll, rr, v);
        add((l + r) / 2 + 1, r, s + s + 1,ll, rr, v);
        combine(f[s], f[s + s], f[s + s + 1]);
    }
    void build(int N) {
        n = N;
        tot = 0;
        dfs(1, 0);
        for (int i = 1; i <= etot; i ++)
            add(1, tot, 1, dfnl[i], dfnr[i] - 1 , w[i]);
    }
    void change_edge_value(int  id, long long v) {
        add(1, tot, 1, dfnl[id], dfnr[id] - 1, v - w[id]);
        w[id] = v;
    }
    long long get_diameter(){
        return f[1].abc;
    }
}
int n, q;
long long w;
int main(){
    scanf("%d %d %lld", &n, &q, &w);
    for (int i = 1; i < n; i ++)
    {
        int x, y;
        long long c;
        scanf("%d %d %lld", &x, &y, &c);
        Dynamic_Diameter::add_edge(x, y, c);
    }
    Dynamic_Diameter::build(n);
    long long ans = 0;
    while (q --) {
        int x;
        long long y;
        scanf("%d %lld", &x, &y);
        x = (x + ans) % (n - 1) + 1;
        y = (y + ans) % w;
        Dynamic_Diameter::change_edge_value(x, y);
        ans = Dynamic_Diameter::get_diameter();
        printf("%lld\n" ,ans);
    }
    return 0;
}