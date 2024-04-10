#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define maxk  101
int D[maxn][maxk];
vector<int> G[maxn];
vector<int> I[maxk];
int main(){
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for(int i = 1; i <= n; i += 1){
        int a;
        scanf("%d", &a);
        I[a].push_back(i);
    }
    for(int i = 1; i <= m; i += 1){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= k; i += 1){
        for(int j = 1; j <= n; j += 1) D[j][i] = 100000;
        queue<int> Q;
        for(int x: I[i]) D[x][i] = 0, Q.push(x);
        while(Q.empty() == false){
            int u = Q.front();
            Q.pop();
            for(int v : G[u])
                if(D[v][i] > D[u][i] + 1)
                    D[v][i] = D[u][i] + 1, Q.push(v);
        }
    }
    for(int i = 1; i <= n; i += 1){
        int ans = 0;
        sort(D[i] + 1, D[i] + k + 1);
        for(int j = 1; j <= s; j += 1) ans += D[i][j];
        printf("%d ", ans);
    }
}