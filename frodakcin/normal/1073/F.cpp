#include <iostream>
#include <cstdio>

#include <cassert>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 100;

typedef vector<int> vi;
#define pb push_back
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define mp make_pair

int N;

bool t[MAXN];

vi adj[MAXN];

void put(int * a, int v) {
    if(v <= 0) return;
    for(int i = 0;i < 2;i++) if(v > a[i]) swap(v, a[i]);
}
struct OPT {
public: 
    int p1, p2, d, d2;
    bool operator < (const OPT& o) const {return d2 != o.d2 ? d2 < o.d2 : d < o.d;}
} opt[MAXN];
int path[MAXN][2][2];

void dfs(const int& n, const int& p = -1) {
    int c = 0;
    bool ct = false;
    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) path[n][i][j] = -10;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        dfs(adj[n][i], n);
        c++;
        ct |= t[adj[n][i]];
        if(!t[adj[n][i]]) {
            int dn = 1 + path[adj[n][i]][0][1], pn = path[adj[n][i]][0][0];
            if(dn > 0) for(int j = 0;j < 2;j++) if(dn > path[n][j][1]) swap(dn, path[n][j][1]), swap(pn, path[n][j][0]);
        } else ct = true;
    }
    if(c >= 2 or ct) t[n] = true;
    
    if(c == 0) path[n][0][0] = n, path[n][0][1] = 0;
    if(path[n][1][1] != -10) opt[n] = {path[n][0][0], path[n][1][0], path[n][0][1] + path[n][1][1], 0};
}

int p[MAXN], d[MAXN];
typedef queue<int> qi;
pii get_far(const int& n) {
    p[n] = -1;
    d[n] = 0;
    qi q;
    q.push(n);
    int l;
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        for(int i = 0;i < adj[c].size();i++) {
            if(adj[c][i] == p[c] or !t[adj[c][i]]) continue;
            p[adj[c][i]] = c;
            d[adj[c][i]] = d[c] + 1;
            q.push(adj[c][i]);
        }
        l = c;
    }
    return mp(l, d[l]);
}

int C;

OPT dfsSol(const int& n, const int& p) {
    OPT ret = {-1, -1, -10, -10}, tp = ret;
    bool leaf = true;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p or !t[adj[n][i]]) continue;
        leaf = false;
        tp = dfsSol(adj[n][i], n), tp.d2++;
        if(ret < tp) ret = tp;
    }
    if(leaf) return opt[n];
    return ret;
}
OPT v[2];
void solve(const int& n) {
    assert(adj[n].size() >= 2);
    v[0] = v[1] = {-1, -1, -10, -10};
    for(int i = 0;i < adj[n].size();i++) {
        OPT tp = dfsSol(adj[n][i], n);
        for(int j = 0;j < 2;j++) if(v[j] < tp) swap(v[j], tp);
    }
    if(v[1].d <= 0) v[1] = opt[n];
}

int main() {
    scanf("%d", &N);
    for(int i = 0, a, b;i < N - 1;i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0;i <= N;i++) {
        t[i] = false;
    }
    
    int rt;
    for(int i = 1;i <= N;i++) if(adj[i].size() >= 3) {dfs((rt = i)); break;}
    
    //for(int i = 1;i <= N;i++) printf("%d %d [%d %d, %d]\n", i, t[i], opt[i].p1, opt[i].p2, opt[i].d);
    
    pii D = get_far(get_far(rt).first);
    C = D.first;
    for(int i = 0;i*2 < D.second;i++) C = p[C];
    
    //printf("%d\n", C);
    
    solve(C);
    
    printf("%d %d\n%d %d\n", v[0].p1, v[1].p1, v[0].p2, v[1].p2);
    
    return 0;
}