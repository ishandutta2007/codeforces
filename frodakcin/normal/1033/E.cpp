#include <cstdio>
#include <iostream>

#include <cassert>
#include <vector>

using namespace std;

#define pb push_back

const int MAXN = 6e2 + 50;
typedef vector<int> vi;
int N;

int query(vi::iterator s, vi::iterator e, int o = -1) {
    int sz = static_cast<int>(e - s) + (o >= 0);
    if(sz <= 1) return 0;
    printf("? %d\n", sz);
    if(o >= 0) printf("%d ", o);
    for(;s != e;s++) printf("%d ", *s);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if(ret == -1) exit(0);
    return ret;
}

int getE(int n, vi arr) {
    int l = 0, r = arr.size();
    int a = query(arr.begin(), arr.end(), n) - query(arr.begin(), arr.end());
    if(a == 0) return -1;
    while(r > l + 1) {
        int m = (l + r)/2;
        if(query(arr.begin() + l, arr.begin() + m, n) > query(arr.begin() + l, arr.begin() + m)) r = m;
        else l = m;
    }
    return arr[l];
}

vi adj[MAXN];

void build_tree() {
    vi ind(N - 1, -1);
    for(int i = 0;i < N - 1;i++) ind[i] = i + 2;
    int o[MAXN], os = 0;
    o[os++] = 1;
    for(int i = 0, t;i < os;i++) {
        while((t = getE(o[i], ind)) != -1) {
            adj[t].pb(o[i]);
            adj[o[i]].pb(t);
            o[os++] = t;
            for(int j = ind.size() - 1;j >= 0;j--) if(ind[j] == t) {ind.erase(ind.begin() + j); break;}
        }
    }
    
    /*
    cerr << os << '\n';
    for(int i = 0;i < os;i++) cerr << o[i] << '\n';
    cerr << '\n';
    //*/
}

vi P[2];
int c[MAXN];

void partition_dfs(int n = 1, int cl = 0, int p = -1) {
    c[n] = cl;
    P[cl].pb(n);
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        partition_dfs(adj[n][i], cl^1, n);
    }
}
int test_partitions() {
    for(int i = 0;i < 2;i++) if(query(P[i].begin(), P[i].end()) > 0) return i;
    return 2;
}

bool find_cycle_dfs(int n, vi& ans, int g, int p = -1) {
    if(n == g) return true;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        if(find_cycle_dfs(adj[n][i], ans, g, n)) {
            ans.pb(n);
            return true;
        }
    }
    return false;
}
void find_cycle(int p, vi& ans) {
    vi nod(0, -1);
    int l = 0, h;
    for(h = 0;h < P[p].size();nod.pb(P[p][h++])) {
        if(query(nod.begin(), nod.end(), P[p][h])) break;
    }
    assert(h < P[p].size());
    int n = P[p][h];
    while(h > l + 1) {
        int m = (l + h)/2;
        if(query(nod.begin() + l, nod.begin() + m, n)) h = m;
        else l = m;
    }
    find_cycle_dfs(n, ans, nod[l]);
    ans.pb(nod[l]);
}

int main() {
    scanf("%d", &N);
    
    int ctr = 2;
    
    build_tree();
    /*
    for(int i = 1;i <= N;i++) {
        cerr << i << ":";
        for(int j = 0;j < adj[i].size();j++) {
            cerr << ' ' << adj[i][j];
        }
        cerr << '\n';
    }
    cerr << '\n';
    //*/
    partition_dfs();
    int fp = test_partitions();
    if(fp == 2) {
        fp = 0;
        printf("Y %lu\n", P[fp].size());
        for(int i = 0;i < P[fp].size();i++) printf("%d ", P[fp][i]);
        return 0;
    }
    
    vi ans(0, -1);
    find_cycle(fp, ans);
    
    assert(ans.size()&1);
    printf("N %lu\n", ans.size());
    for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}