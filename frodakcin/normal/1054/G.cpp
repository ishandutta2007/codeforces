#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>
#include <bitset>

using namespace std;

const int MAXN = 2e3 + 100;
const int MAXM = 2e3 + 100;
typedef vector<int> vi;
#define pb push_back

int N, M;
bitset<MAXM> g[MAXN];
char inp[MAXM][MAXN];
int ct[MAXM];
vi po[MAXN];
bool r[MAXN], usd[MAXN][MAXN];
int ind[MAXN][MAXN];
vi c[MAXN];
int edg[MAXN][2];

void rnode(int n, int n2) {
    assert(!r[n]);
    r[n] = true;
    for(int i = 1;i <= N;i++) if(!r[i]) if(usd[i][n]) {
        int sw = c[i].back();
        if(sw != i) {
            swap(c[i][c[i].size() - 1], c[i][ind[i][n]]);
            swap(ind[i][sw], ind[i][n]);
        }
        assert(ind[i][n] == c[i].size() - 1);
        ind[i][n] = -1;
        c[i].pop_back();
    }
    bool rn = false;
    for(int i = 0;i < po[n].size();i++) {
        ct[po[n][i]]--;
        if(ct[po[n][i]] == 1) {
            ct[po[n][i]] = 0;
            g[n2][po[n][i]] = 0;
            rn = true;
        }
    }
    if(rn) {
        for(int j = 1;j <= N;j++) {
            if(r[j] or j == n2 or usd[n2][j]) continue;
            if((g[n2]&g[j]) == g[n2]) ind[n2][j] = c[n2].size(), c[n2].pb(j), usd[n2][j] = true;
        }
    }
}

void solve() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i <= N;i++) for(int j = 0;j <= N;j++) usd[i][j] = false, ind[i][j] = -1;
    for(int i = 0;i <= N;i++) g[i] = 0, po[i].assign(0, -1), c[i].assign(0, -1), r[i] = false;
    for(int i = 0;i < M;i++) {
        scanf(" %s", inp[i]);
        ct[i] = 0;
        for(int j = 0;j < N;j++) if(inp[i][j] == '1') ct[i]++;
        if(ct[i] > 1) {for(int j = 0;j < N;j++) if(inp[i][j] == '1') g[j + 1][i] = 1, po[j + 1].pb(i);}
        else ct[i] = 0;
    }
    
    for(int i = 1;i <= N;i++) for(int j = 1;j <= N;j++) if(i != j and (g[i]&g[j]) == g[i]) ind[i][j] = c[i].size(), c[i].pb(j), usd[i][j] = true;
    
    bool a = true;
    for(int e = 0;e < N - 1;e++) {
        int f = -1;
        for(int i = 1;i <= N;i++) {
            if(!r[i] and !c[i].empty()) {f = i; break;}
        }
        if(f == -1) {
            a = false;
            break;
        }
        
        int ft = c[f].back();
        edg[e][0] = f;
        edg[e][1] = ft;
        assert(!r[ft]);
        rnode(f, ft);
    }
    if(a) {
        printf("YES\n");
        for(int i = 0;i < N - 1;i++) printf("%d %d\n", edg[i][0], edg[i][1]);
    } else printf("NO\n");
}


int T;
int main() {
    scanf("%d", &T);
    for(int t = 0;t < T;t++) solve();
    return 0;
}