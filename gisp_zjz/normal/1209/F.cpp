#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e6+3;
const int M=1000000007;
typedef vector<int> vi;
int cnt,n,m,d[10],r,t,dis[maxn];
vector <int> h[maxn][10];
void add_edge(int u,int v,int w){
    r=0; while (w) d[++r]=w%10,w/=10;
    for (int i=r;i>1;i--) h[u][d[i]].pb(++cnt),u=cnt;
    h[u][d[1]].pb(v);
}
int main(){
    scanf("%d%d",&n,&m); cnt=n;
    for (int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d",&u,&v); w=i;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    memset(dis,-1,sizeof(dis)); dis[1]=0;
    vi res=(vi)(1); res.pb(1);
    queue <vi> q; q.push(res);
    while (!q.empty()){
        vi tmp=q.front(); q.pop();
        for (int i=0;i<10;i++){
            vi res=(vi)(0);
            for (auto u:tmp){
                for (auto v:h[u][i]){
                    if (dis[v]!=-1) continue;
                    dis[v]=(1ll*dis[u]*10+i)%M;
                    res.pb(v);
                }
            }
            if (res.size()) q.push(res);
        }
    }
    for (int i=2;i<=n;i++) printf("%d\n",dis[i]);
    return 0;
}