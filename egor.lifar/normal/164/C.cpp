#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
const int INF = 1000 * 1000 * 1000;
const int MAXN = 10000;
int n, k;
int s[MAXN], t[MAXN], c[MAXN];


struct edge {
    int to, flow, cap, p, rev;
};


vector<edge> g[MAXN];


inline void addEdge(int fr, int to, int cap, int p){
    edge a = {to, 0, cap, p, sz(g[to])};
    edge b = {fr, 0, 0, -p, sz(g[fr])};
    g[fr].push_back(a);
    g[to].push_back(b);
}


int d[MAXN], tr[MAXN], trE[MAXN];
int Head, Tale;
int q[MAXN];
bool used[MAXN];


void enlarge(int s, int t){
    for (int i = 0; i <= t; i++) {
        d[i] = INF + 10;
    }
    Head = Tale = 0;
    q[Tale++] = s;
    d[s] = 0;
    tr[s] = s;
    trE[s] = -1;
    while (Head != Tale) {
        int v = q[Head++];
        if (Head == MAXN) {
            Head = 0;
        }
        used[v] = false;
        for (int i = 0; i < sz(g[v]); i++) {
            int u = g[v][i].to;
            if (d[u] > d[v] + g[v][i].p && g[v][i].cap > g[v][i].flow) {
                d[u] = d[v] + g[v][i].p;
                tr[u] = v;
                trE[u] = i;
                if (!used[u]) {
                    used[u] = true;
                    q[Tale++] = u;
                    if (Tale == MAXN) {
                        Tale = 0;
                    }
                }
            }
        }
    }
    if (d[t] > INF) {
        return;
    }
    for (int b = t; b != s; b = tr[b]) {
        g[tr[b]][trE[b]].flow++;
        g[b][g[tr[b]][trE[b]].rev].flow--;
    }
}                 


int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[i], &t[i], &c[i]);
    }
    int sr = 2 * n, tr = 2 * n + 1;
    for (int i = 0; i < n; i++) {
        addEdge(sr, i, 1, 0);
        addEdge(i, n + i, 1, -c[i]);
        addEdge(n + i, tr, 1, 0);
        for (int j = 0; j < n; j++) {
            if (s[j] >= s[i] + t[i]) {
                addEdge(n + i, j, 1, 0);
            }
        }       
    }
    for (int i = 0; i < k; i++) {
        enlarge(sr, tr);
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < sz(g[i]); j++) {
            if (g[i][j].to == n + i && g[i][j].flow == 1){
                ans = 1;
                break;
            }
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}