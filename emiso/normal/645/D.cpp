#include <bits/stdc++.h>

#define MN 100100
using namespace std;

int n, m, u[MN], v[MN], degree[MN];
vector<int> adj[MN];

bool topsort() {
    int next = 0;
    for(int i=1; i<=n; i++)
        if(!degree[i]) {
            if(!next) next = i;
            else return false;
        }

    while(next != 0) {
        int u = next;
        next = 0;

        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            degree[v]--;
            if(!degree[v]) {
                if(!next) next = v;
                else return false;
            }
        }
    }
    return true;
}

void cls() {
    memset(degree, 0, sizeof degree);
    for(int i=0;i<=n;i++)
        adj[i].clear();
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        scanf("%d %d", &u[i], &v[i]);
    }
    int low = 1, high = m+1;
    while(low < high) {
        int mid = (low + high) / 2;
        //printf("%d %d %d\n", low, mid, high);

        cls();
        for(int i=0;i<mid;i++) {
            adj[u[i]].push_back(v[i]);
            degree[v[i]]++;
        }

        if(topsort())
            high = mid;
        else
            low = mid + 1;

    }

    if(low > m) printf("-1\n");
    else printf("%d\n",low);

    return 0;
}