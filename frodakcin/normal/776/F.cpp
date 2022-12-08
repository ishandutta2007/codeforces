#include <iostream>
#include <cstdio>

#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 1e5 + 1000;
const int MAXM = MAXN;

typedef vector<int> vi;
#define pb push_back

int N, M;

int l[MAXN], ls;
vi seg[MAXN];
vi rem[MAXN];
int cn;

vi adj[MAXN];
void connect(const int& a, const int& b) {
    adj[a].pb(b);
    adj[b].pb(a);
}

int s[MAXN], ans[MAXN];
bool t[MAXN];
int dfs(const int& n, const int& p = -1) {
    s[n] = 1;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p or !t[adj[n][i]]) continue;
        s[n] += dfs(adj[n][i], n);
    }
    return s[n];
}
int get_centroid(const int& n, const int& ms, const int& p = -1) {
    assert(s[n] * 2 >= ms);
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p or !t[adj[n][i]]) continue;
        if(s[adj[n][i]] * 2 > ms) return get_centroid(adj[n][i], ms, n);
    }
    return n;
}
int get_centroid(const int& n) {
    return get_centroid(n, dfs(n));
}
void solve(const int& n, const int& r = 1) {
    int c = get_centroid(n);
    ans[c] = r;
    t[c] = false;
    for(int i = 0;i < adj[c].size();i++) if(t[adj[c][i]]) solve(adj[c][i], r + 1);
}


int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0, a, b;i < M;i++) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        seg[b].pb(a);
    }
    for(int i = 1;i <= N;i++) sort(seg[i].begin(), seg[i].end());
    
    cn = ls = 0;
    bool f = false;
    
    if(seg[N].size()) {
        int v = seg[N].size();
        l[ls++] = v;
        for(int i = 0;i < v;i++) {
            connect(l[ls - 1], cn + v - i - 1);
            l[ls++] = cn + v - i - 1;
            rem[seg[N][i]].pb(cn + v - i - 1);
        }
        cn += v + 1;
    } else l[ls++] = cn++;
    
    for(int i = N - 1;i >= 1;i--) {
        for(int j = rem[i].size() - 1;j >= 0;j--) {
            assert(ls and l[ls - 1] == rem[i][j]);
            ls--;
        }
        int v = seg[i].size();
        for(int j = 0;j < v;j++) {
            connect(l[ls - 1], cn + v - j - 1);
            l[ls++] = cn + v - j - 1;
            rem[seg[i][j]].pb(cn + v - j - 1);
        }
        cn += v;
    }
    assert(cn == M + 1);
    
    //for(int i = 0;i < cn;i++) for(int j = 0;j < adj[i].size();j++) printf("%d %d\n", i, adj[i][j]);
    
    for(int i = 0;i < cn;i++) t[i] = true;
    
    solve(0);
    
    for(int i = cn - 1;i >= 0;i--) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}