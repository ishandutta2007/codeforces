#include <iostream>
#include <cstdio>

#include <vector>
#include <stack>
#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 3e5 + 100;
const int MAXM = 3e5 + 100;

typedef vector<int> vi;
#define pb push_back

int N, M;
vi adj[MAXN], adjr[MAXN];

int lp[MAXN], lpl;
int pos[MAXN];
int d[MAXN];

int rpl(int& a, const int& b) {
    if(a < b) a = b;
    return a;
}
int dfs(const int& n) {
    d[n] = 1;
    for(int i = 0;i < adj[n].size();i++) if(d[adj[n][i]] != -1) rpl(d[n], d[adj[n][i]] + 1); else rpl(d[n], dfs(adj[n][i]) + 1);
    return d[n];
}

bool vis[MAXN];
int dfs2(const int& n, vi * a, int * s) {
    assert(!vis[n]);
    vis[n] = true;
    s[n] = 1;
    for(int i = 0;i < a[n].size();i++) if(!vis[a[n][i]]) s[n] += dfs2(a[n][i], a, s);
    return s[n];
}
int out[MAXN], in[MAXN];


int cn[MAXN], cnB[MAXN], cnT[MAXN], cns, cno[MAXN];
bool cnw[MAXN];
void testcn(const int& n) {
    cnB[cns] = -1, cnT[cns] = lpl, cn[cns] = n;
    for(int i = 0;i < adj[n].size();i++) if(pos[adj[n][i]] != -1 and pos[adj[n][i]] > cnB[cns]) cnB[cns] = pos[adj[n][i]];
    for(int i = 0;i < adjr[n].size();i++) if(pos[adjr[n][i]] != -1 and pos[adjr[n][i]] < cnT[cns]) cnT[cns] = pos[adjr[n][i]];
    if(cnB[cns] + 2 == cnT[cns]) cnw[cns++] = true;
}

int dfs3a(const int& n, vi * a) {
    vis[n] = true;
    int r = 1;
    for(int i = 0;i < a[n].size();i++) if(!vis[a[n][i]]) r += dfs3a(a[n][i], a);
    return r;
}
typedef stack<int> stki;
int dfs3b(const int& n, vi * a, stki& s) {
    s.push(n);
    vis[n] = true;
    int r = 1;
    for(int i = 0;i < a[n].size();i++) if(!vis[a[n][i]]) r += dfs3b(a[n][i], a, s);
    return r;
}
int dfs3b(const int& n, vi * a) {
    stki s;
    int r = dfs3b(n, a, s);
    while(!s.empty()) vis[s.top()] = false, s.pop();
    return r;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0, u, v;i < M;i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adjr[v].pb(u);
    }
    
    for(int i = 0;i <= N;i++) d[i] = -1, pos[i] = -1;
    
    lpl = -1;
    for(int i = 1, t;i <= N;i++) if(d[i] == -1) if((t = dfs(i)) > lpl) lpl = t, lp[lpl-1] = i;
    
    pos[lp[lpl-1]] = lpl-1;
    for(int i = lpl - 1;i >= 1;i--) {
        for(int j = 0, f = 0;f == 0;j++, f++) if(d[adj[lp[i]][j]] == i) lp[i-1] = adj[lp[i]][j], pos[adj[lp[i]][j]] = i-1; else f--;
    }
    
    for(int i = 0;i <= N;i++) out[i] = in[i] = -1;
    
    for(int i = 0;i <= N;i++) vis[i] = false;
    for(int i = 0;i < lpl;i++) {
        assert(!vis[lp[i]]);
        dfs2(lp[i], adj, out);
        if(i) out[lp[i]] += out[lp[i-1]];
    }
    assert(out[lp[0]] == 1);
    
    for(int i = 0;i <= N;i++) vis[i] = false;
    for(int i = lpl - 1;i >= 0;i--) {
        assert(!vis[lp[i]]);
        dfs2(lp[i], adjr, in);
        if(i < lpl - 1) in[lp[i]] += in[lp[i + 1]];
    }
    assert(in[lp[lpl - 1]] == 1);
    
    cns = 0;
    for(int i = 0;i <= N;i++) cnw[i] = false;
    for(int i = 1;i <= N;i++) if(pos[i] == -1) testcn(i);
    for(int i = 0;i <= N;i++) cno[i] = i;
    sort(cno, cno + cns, [](const int& a, const int& b){return cnB[a] < cnB[b];});
    
    for(int i = 0;i <= N;i++) vis[i] = false;
    int k = 0;
    for(int i = 0, j;i < cns;i = j) {
        for(j = i + 1;j < cns and cnB[cno[j]] == cnB[cno[i]];) cnw[cno[j++]] = false;
        if(j > i + 1) {cnw[cno[i]] = false; continue;}
        
        for(;k <= cnB[cno[i]];k++) assert(dfs3a(lp[k], adj) == (k > 0 ? out[lp[k]] - out[lp[k-1]] : out[lp[k]]));
        out[cn[cno[i]]] = dfs3b(cn[cno[i]], adj) + (cnB[cno[i]] == -1 ? 0 : out[lp[cnB[cno[i]]]]);
    }
    
    for(int i = 0;i <= N;i++) vis[i] = false;
    k = lpl - 1;
    for(int i = cns - 1;i >= 0;i--) {
        if(cnw[cno[i]]) {
            for(;k >= cnT[cno[i]];k--) assert(dfs3a(lp[k], adjr) == (k < lpl - 1 ? in[lp[k]] - in[lp[k + 1]] : in[lp[k]]));
            in[cn[cno[i]]] = dfs3b(cn[cno[i]], adjr) + (cnT[cno[i]] == lpl ? 0 : in[lp[cnT[cno[i]]]]);
        }
    }
    
    int ans = 0;
    for(int i = 0;i < lpl;i++) ans += (in[lp[i]] + out[lp[i]] >= N);
    for(int i = 0;i < cns;i++) if(cnw[i]) ans += (in[cn[i]] + out[cn[i]] >= N);
    
    printf("%d\n", ans);
    
    return 0;
}
/*
6 7
1 2
2 4
4 5
6 5
2 6
3 2
3 6
*/