#include<bits/stdc++.h>
#define maxn 205050

using namespace std;
typedef long long ll;
bool vis[maxn],f[maxn],sp[maxn];
vector <int> H[maxn],h[maxn];
ll w[maxn],dis[100][maxn],ans,sum[maxn],ans2,S[maxn],T[maxn];
int n,m,d[maxn],p[100],cnt,cc,a[maxn],rev[maxn];
queue <int> q;

void bfs(int id){
    vis[p[id]]=1;
    while (!q.empty()) q.pop(); q.push(p[id]);
    while (!q.empty()){
        int u=q.front(); q.pop();
        if (sp[u]) ans2+=dis[id][u]*w[u]*w[p[id]]; else ans+=dis[id][u]*w[u]*w[p[id]];
        for (int i=0;i<H[u].size();i++){
            int v=H[u][i];
            if (vis[v]) continue;
            dis[id][v]=dis[id][u]+1;
            vis[v]=1; q.push(v);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) w[i]=1;
    for (int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        h[u].push_back(v);
        h[v].push_back(u);
        d[u]++; d[v]++;
    }
    for (int i=1;i<=n;i++) if (d[i]==1) q.push(i);
    while (!q.empty()){
        int u=q.front(); q.pop(); f[u]=1;
        if (d[u]!=1) continue;
        for (int i=0;i<h[u].size();i++){
            int v=h[u][i];
            if (f[v]) continue;
            ans+=w[u]*(n-w[u]);
            w[v]+=w[u]; w[u]=0; d[v]--;
            if (!d[v]){printf("%lld\n",ans);return 0;}
            if (d[v]==1) q.push(v);
        }
    }
    for (int i=1;i<=n;i++) if (!f[i]){
        for (int j=0;j<h[i].size();j++){
            int v=h[i][j];
            if (!f[v]) H[i].push_back(v);
        }
    }
    cnt=0;
    for (int i=1;i<=n;i++) if (!f[i]&&d[i]>2) p[++cnt]=i,rev[i]=cnt;
    if (!cnt) {
        for (int i=1;i<=n;i++) if (!f[i]) {p[++cnt]=i;rev[i]=cnt;break;}
        for (int i=p[1]+1;i<=n;i++) if (!f[i]) {p[++cnt]=i;rev[i]=cnt;break;}
    }
    for (int i=1;i<=cnt;i++) sp[p[i]]=1;
    for (int i=1;i<=cnt;i++){
        bfs(i);
        memset(vis,0,sizeof(vis));
    }
    for (int i=1;i<=cnt;i++){
        int u=p[i];
        for (int j=0;j<H[u].size();j++){
            int last=u,v=H[u][j]; cc=0;
            if (f[v]||sp[v]) continue;
            while (!sp[v]){
                a[++cc]=v;
                f[v]=vis[v]=1;
                int tmp=last;
                last=v;
                v=H[v][0]+H[v][1]-tmp;
            }
            for (int k=1;k<=cc;k++) sum[k]=sum[k-1]+w[a[k]];
            S[0]=0; for (int k=1;k<=cc;k++) S[k]=S[k-1]+w[a[k]]*k;
            T[cc+1]=0; for (int k=cc;k;k--) T[k]=T[k+1]+w[a[k]]*(cc+1-k);
            int len=dis[i][v];
            //cout<<len<<endl;
            for (int k=1;k<cc;k++){
                int x=(k*2+cc+1+len)/2;
                if (x>cc) x=cc;

                //cout<<x<<endl;
                ans+=w[a[k]]*(T[x+1]+(len+k)*(sum[cc]-sum[x])+S[x]-S[k]-k*(sum[x]-sum[k]));
                //cout<<(T[x+1]+(len+k)*(cc-x))<<' '<<(S[x]-S[k]-sum[k]*(x-k))<<endl;
            }
            for (int k=1;k<=n;k++) if (w[k]&&!vis[k]&&!sp[k]){
                ll P=dis[i][k],Q=dis[rev[v]][k];
                int x=((Q-P)+(cc+1))/2;
                if (x>cc) x=cc; if (x<0) x=0;
                ans2+=w[k]*(sum[x]*P+(sum[cc]-sum[x])*Q+S[x]+T[x+1]);
            }
            for (int k=1;k<=cc;k++) vis[a[k]]=0;
        }
    }
    printf("%lld\n",ans+ans2/2);
    return 0;
}