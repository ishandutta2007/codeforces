#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int pd[5010][5010],T,qu,n;
vector <pair<int,int> > adj[5010], adjr[5010];
stack<int> ord;

void solve() {
    for(int i=0;i<5010;i++)
        for(int j=0;j<5010;j++)
            pd[i][j] = 2022222222;

    pd[1][1] = 0;

    queue<pair<int,int> > fila;
    fila.push({1,1});

    while(!fila.empty()) {
        pair<int, int> p = fila.front();
        fila.pop();

        int u = p.first;
        int q = p.second;

        if(pd[u][q] > T) continue;

        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i].first;
            int c = adj[u][i].second;

            if(pd[v][q+1] > pd[u][q] + c) {
                pd[v][q+1] = pd[u][q] + c;
                fila.push({v,q+1});
            }
        }
    }

    int u = n,qt;
    ord.push(n);

    for(int i = n; i > 0; i--) {
        if(pd[n][i] <= T) {
            qu = i;
            break;
        }
    } qt = qu;
    while(u != 1) {
        for(int i=0;i<adjr[u].size();i++) {
            int v = adjr[u][i].first;
            int c = adjr[u][i].second;

            if(pd[v][qt-1] + c == pd[u][qt]) {
                u = v;
                ord.push(u);
                break;
            }
        }
        qt--;
    }

}

int main() {
    int m,t,u,v;
    scanf("%d %d %d",&n, &m, &T);

    for(int i=0; i<m; i++) {
        scanf("%d %d %d",&u, &v, &t);
        adj[u].push_back(make_pair(v,t));
        adjr[v].push_back(make_pair(u,t));
    }

    solve();

    printf("%d\n",qu);
    while(!ord.empty()) {
        printf("%d ",ord.top());
        ord.pop();
    }
    return 0;
}