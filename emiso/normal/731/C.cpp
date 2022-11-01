#include <bits/stdc++.h>

#define MN 200200

using namespace std;

int ans, comp_size, maior, n, m, k, visit[MN], c[MN];
vector<int> adj[MN];
map<int,int> freq;

void dfs(int node) {
    if(visit[node]) return;

    visit[node]++;
    freq[c[node]]++;
    maior = max(maior, freq[c[node]]);
    comp_size++;

    for(int i=0;i<adj[node].size();i++)
        dfs(adj[node][i]);
}

int main() {
    int l,r;
    scanf("%d %d %d", &n ,&m ,&k);

    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
    }
    for(int i=0;i<m;i++) {
        scanf("%d %d",&l,&r);
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    for(int i=1;i<=n;i++) {
        if(!visit[i]) {
            maior = comp_size = 0;
            freq.clear();

            dfs(i);
            ans += (comp_size - maior);
        }
    }

    printf("%d\n", ans);
}