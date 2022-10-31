#include <bits/stdc++.h>

#define MN 100100

using namespace std;

vector <int> adj[MN], red, tempred;

int visit[MN],dist[MN],distred[MN];
int prnt[MN][20],N,m,sqm, redp[MN];

int meulog(int base) {
    int j;
    for(j=1;1<<j<=base;j++);
    return --j;
}

void dfs(int node) {
    visit[node]++;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];

        if(!visit[v]) {
            dist[v] = dist[node] + 1;
            prnt[v][0] = node;
            dfs(v);
        }
    }
}

void buildlca(int root) {
    prnt[root][0] = root;

    for(int j=1; 1<<j <= N;j++) {
        for(int i = 1;i <= N;i++) {
            prnt[i][j] = prnt[prnt[i][j-1]][j-1];
        }
    }
}

void bfs() {
    memset(visit,0,sizeof(visit));
    memset(distred,0,sizeof(distred));
    queue<int> fila;

    for(int i=0; i<red.size(); i++) {
        visit[red[i]] = 1;
        distred[red[i]] = 0;
        fila.push(red[i]);
    }

    while(!fila.empty()) {
        int f = fila.front();
        fila.pop();
        for(int i=0;i<adj[f].size();i++) {
            int v = adj[f][i];
            if(!visit[v]) {
                distred[v] = distred[f] + 1;
                visit[v]++;
                fila.push(v);
            }
        }
    }
}

void update(int node) {
    if(!redp[node]) {
        tempred.push_back(node);
        redp[node] = 1;
    }

    if(tempred.size() >= sqm) {
        while(!tempred.empty()) {
            red.push_back(tempred.back());
            tempred.pop_back();
        }
        bfs();
    }
}

int querylca(int a,int b) {
    if(dist[a] < dist[b]) swap(a,b);

    for(int i = meulog(N); i>=0; i--)
        if(dist[a] - dist[b] >= 1<<i)
            a = prnt[a][i];

    if(a==b) return a;

    for(int i = meulog(N); i >=0; i--) {
        if(prnt[a][i] != prnt[b][i]) {
            a = prnt[a][i];
            b = prnt[b][i];
        }
    }

    return prnt[a][0];
}

int query(int node) {
    int res = (red.empty()) ? 9999999 : distred[node];
    for(int i=0; i<tempred.size(); i++) {
        int ancestor = querylca(node,tempred[i]);
        res = min(res,dist[node] + dist[tempred[i]] - (2*dist[ancestor]));
    }
    return res;
}

int main() {
    int a,b,t,v;

    scanf("%d %d",&N,&m);
    sqm = (int)sqrt(m);

    for(int i=1;i<N;i++) {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    buildlca(1);
    tempred.push_back(1);
    redp[1] = 1;

    for(int i=0;i<m;i++) {
        scanf("%d %d",&t,&v);

        if(t&1) update(v);
        else printf("%d\n",query(v));
    }
    return 0;
}