#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> vi;
#define pb push_back

const int RN = 26;
const int MAXN = 1e5 + 100;

int N;

vi adj[MAXN];

bool ans;
int r[MAXN];

bool t[MAXN];

int s[MAXN];
int dfs(const int& n, const int& p = -1) {
    s[n] = 1;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p or !t[adj[n][i]]) continue;
        s[n] += dfs(adj[n][i], n);
    }
    return s[n];
}
int get_centroid(const int& n, const int& ms, const int& p = -1) {
    assert(2 * s[n] >= ms - s[n]);
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p or !t[adj[n][i]]) continue;
        if(s[adj[n][i]] * 2 > ms) return get_centroid(adj[n][i], ms, n);
    }
    return n;
}
int get_centroid(const int& n) {
    return get_centroid(n, dfs(n));
}
void solve(const int& n, const int& cr = 0) {
    if(cr >= RN) ans = false;
    int c = get_centroid(n);
    r[c] = cr;
    t[c] = false;
    for(int i = 0;i < adj[c].size();i++) if(t[adj[c][i]]) solve(adj[c][i], cr + 1);
}

int main() {
    scanf("%d", &N);
    for(int i = 0, a, b;i < N - 1;i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ans = true;
    for(int i = 1;i <= N;i++) t[i] = true;
    
    solve(1);
    
    if(ans) {
        for(int i = 1;i <= N;i++) printf("%c ", static_cast<char> (r[i] + 'A'));
        printf("\n");
    } else printf("Impossible!\n");
    return 0;
}