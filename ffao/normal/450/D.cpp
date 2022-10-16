#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

vector<pii> adj[110000];
long long dist[110000];
int seen[110000];
int n,m,k;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    REP(i,m) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c); u--; v--;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    REP(i,n) dist[i] = 1000000000000000000LL;
    REP(i,k) {
        int u,c;
        scanf("%d %d", &u, &c); u--;
        dist[u] = min(dist[u], (ll)c);
    }

    dist[0] = 0;
    set< pair<long long, int> > nodes;
    REP(i,n) nodes.insert({dist[i], i});

    while (!nodes.empty()) {
        int curr = nodes.begin()->second;
        nodes.erase(nodes.begin());

        for (pii p : adj[curr]) {
            long long nd = dist[curr] + p.second;
            if (nd < dist[p.first]) {
                nodes.erase({dist[p.first], p.first});
                dist[p.first] = nd;
                nodes.insert({dist[p.first], p.first});
            }
        }
    }

    int del = k;
    for (int i = 1; i < n; i++) {
        bool ok = false;
        for (pii p: adj[i]) {
            if (dist[i] == dist[p.first] + p.second) ok = true;
        }
        del -= !ok;
    }

    printf("%d\n", del);
}