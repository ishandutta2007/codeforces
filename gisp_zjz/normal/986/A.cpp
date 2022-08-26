#include<bits/stdc++.h>
#define maxn 203040

using namespace std;
int a[maxn],d[maxn][105],n,m,s,k,b[105],c;
vector <int> h[maxn];
queue <int> q;

int main(){
    cin >> n >> m >> k >> s;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<m;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    for (int i=1;i<=k;i++){
        while (!q.empty()) q.pop();
        for (int j=1;j<=n;j++) if (a[j]==i){
            q.push(j); d[j][i]=0;
        }
        else d[j][i]=-1;
        while (!q.empty()){
            int u=q.front(); q.pop();
            for (int j=0;j<h[u].size();j++){
                int v=h[u][j];
                if (d[v][i]==-1){
                    d[v][i]=d[u][i]+1;
                    q.push(v);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++) b[j]=d[i][j];
        sort(b+1,b+k+1); c=0;
        for (int j=1;j<=s;j++) c+=b[j];
        cout << c << ' ';
    }
    cout << endl;
}