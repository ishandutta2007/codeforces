#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e6+3;
int n,m,a[maxn],s,t,d,dis[maxn],cnt[maxn],a1,a2;
vector <int> h[maxn];
queue <int> q;
int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        int u,v;scanf("%d%d",&u,&v);
        h[v].pb(u);
    }
    scanf("%d",&d);
    for (int i=1;i<=d;i++) scanf("%d",&a[i]);
    s=a[1]; t=a[d];
    memset(dis,-1,sizeof(dis));
    dis[t]=0;
    q.push(t);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (auto v:h[u]){
            if (dis[v]==-1){
                dis[v]=dis[u]+1,q.push(v);
            } else if (dis[v]==dis[u]+1){
                cnt[v]=1;
            }
        }
    }
    for (int i=1;i<d;i++){
        int u=a[i],v=a[i+1];
        if (dis[u]!=dis[v]+1) a1++;
        else if (cnt[u]) a2++;
    }
    cout << a1 << ' ' << a1+a2 << endl;
    return 0;
}