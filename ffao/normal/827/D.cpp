#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
 
 
using namespace std;
 
 
#include <tuple>
 
 
void re(int& x);
 
 
template<class T, class... Ts> void re(T& t, Ts&... ts);
 
 
typedef pair<int, int> pii;
 
 
#define all(v) (v).begin(), (v).end()
 
 
int par[210000];
int rk[210000];
int super[210000];
 
int sz = 0;
pair<int*, pii> ops[610000];
 
void Set(int* ar, int x, int val) {
    ops[sz++] = {ar, {x, ar[x]}};
    ar[x] = val;
}
 
void Undo() {
    sz--;
    ops[sz].first[ops[sz].second.first] = ops[sz].second.second;
}
 
int find(int a) {
    if (par[a] == a) return a;
    return find(par[a]);
}
 
void link(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
 
    if (rk[x] < rk[y]) swap(x,y);
    Set(par, y, x);
    Set(rk, x, rk[x]+rk[y]);
}
 
int n,m;
vector< pair<pii, pii> > edges;
 
int idx(int x) {
    return edges[x].first.second;
}
 
void go(int l, int r, const vector<int>& v) {
    if (l == r) {
        
        for (int i : v) {
            if (i != l) {
                //printf("%d (%d) supersedes %d (%d) and goes to %d-1\n", edges[l].first.second, l, edges[i].first.second, i, edges[l].first.first);
                super[ idx(i) ] = edges[l].first.first - 1;
            }
            //else printf("%d in tree\n", i);
        }
        return;
    }
 
    int m = (l+r)/2;
    int cur_st = sz;
 
    for (int i = l; i <= m; i++) {
        link(edges[i].second.first, edges[i].second.second);
    }
 
    vector<int> left, right;
    for (int i : v) {
        if (find(edges[i].second.first) != find(edges[i].second.second)) {
            right.push_back(i);
        }
        else left.push_back(i);
    }
 
    go(m+1,r,right);
 
    while (sz > cur_st) Undo();
 
    go(l,m,left);
}
 
vector<pii> G[210000];
set< pii > bad_edges[210000];
 
void dfs(int v, int pai, int e) {
    for (pii p : G[v]) if (p.first != pai) {
        int x = p.first;
        dfs(x, v, p.second);
 
        if (bad_edges[x].size() > bad_edges[v].size()) swap(bad_edges[x], bad_edges[v]);
        for (pii kk : bad_edges[x]) {
            if (bad_edges[v].count(kk)) bad_edges[v].erase(kk);
            else bad_edges[v].insert(kk);
        }
    }
 
    if (!bad_edges[v].empty()) super[idx(e)] = bad_edges[v].begin()->first - 1;
    else if (e != -1) super[idx(e)] = -1;
}
 
void solve()
{
    re(n,m);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rk[i] = 1;
    }
 
    for (int i = 0; i < m; i++) {
        int u,v,c;
        re(u,v,c); u--; v--;
 
        edges.push_back({{c, i}, {u,v}});
        super[i] = 1100000000;
    }
 
    sort(all(edges));
    
    
 
    for (int i = 0; i < m; i++) {
        int x = find(edges[i].second.first), y = find(edges[i].second.second);
        if (x != y) {
            link(x,y);
            G[edges[i].second.second].push_back({edges[i].second.first, i});
            G[edges[i].second.first].push_back({edges[i].second.second, i});
        }
        else {
            bad_edges[edges[i].second.second].insert({edges[i].first.first, i});
            bad_edges[edges[i].second.first].insert({edges[i].first.first, i});
        }
    }
 
    dfs(0,-1, -1);
 
    sz = 0;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rk[i] = 1;
    }
 
    vector<int> everyone(m);
    for (int i = 0; i < m; i++) everyone[i] = i;
 
    go(0, m-1, everyone);
 
    for (int i = 0; i < m; i++) {
        printf("%d ", super[i]);
    }
}
 
 
int main() {
 
 
    solve();
}
 
 
void re(int& x) { scanf("%d", &x); }
 
 
template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}