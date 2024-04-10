#include<bits/stdc++.h>
using namespace std;
#define maxn 500020
const int inf=1e9+100;
struct edge{
    int to,c;
};

edge e[maxn];
int h[maxn],nxt[maxn];
set <int> S;
map <int,int> f;
int invx[105],invy[105],X[105],Y[105],N,cnt,tmp[105],R,C;
int a[maxn],n,m,p,s,t,dis[maxn],sz[maxn];
bool mp[105][105];
void add_edge(int x,int y,int z){
    e[p].to=y;e[p].c=z;nxt[p]=h[x];h[x]=p;sz[x]++;p++;
    e[p].to=x;e[p].c=0;nxt[p]=h[y];h[y]=p;sz[y]++;p++;
}
bool bfs(){
    queue <int> q;
    for (int i=1;i<=n;i++) dis[i]=-1;
    dis[s]=0;
    q.push(s);
    while (!q.empty()){
        int cur=q.front();q.pop();
        for (int i=h[cur];i!=-1;i=nxt[i]){
            int tt=e[i].to;
            if (dis[tt]==-1&&e[i].c>0){
                dis[tt]=dis[cur]+1;
                q.push(tt);
            }
        }
    }
    return (dis[t]!=-1);
}

int findf(int x,int flow){
    if (x==t) return flow;
    int a;
    for (int i=h[x];i!=-1;i=nxt[i]){
        int tt=e[i].to;
        if (dis[tt]==dis[x]+1&&e[i].c>0&&(a=findf(tt,min(flow,e[i].c)))){
            e[i].c-=a;
            e[i^1].c+=a;
            return a;
        }
    }
    return 0;
}

int dinic(){
    int tmp,ans;ans=0;
    while (bfs()){
        tmp=findf(s,inf);
        ans+=tmp;
    }
    return ans;
}

int main(){
    scanf("%d%d",&N,&N);
    if (N==0){puts("0");return 0;}
    for (int i=0;i<N*2;i++) scanf("%d%d",&X[i],&Y[i]);
    for (int i=0;i<N*2;i+=2) X[i]--,Y[i]--;
    cnt=0; S.clear(); f.clear();
    for (int i=0;i<N*2;i++) if (S.find(X[i])==S.end()) S.insert(X[i]);
    for (auto x:S) f[x]=++cnt,invx[cnt]=x;
    for (int i=0;i<N*2;i++) X[i]=f[X[i]]; R=cnt-1;
    cnt=0; S.clear(); f.clear();
    for (int i=0;i<N*2;i++) if (S.find(Y[i])==S.end()) S.insert(Y[i]);
    for (auto y:S) f[y]=++cnt,invy[cnt]=y;
    for (int i=0;i<N*2;i++) Y[i]=f[Y[i]]; C=cnt-1;
    for (int i=0;i<N*2;i+=2){
        for (int x=X[i];x<X[i+1];x++)
        for (int y=Y[i];y<Y[i+1];y++)
            mp[x][y]=1;
    }
    s=R+C+1; t=R+C+2; n=t;
    memset(h,-1,sizeof(h));
    for (int i=1;i<=R;i++) add_edge(s,i,invx[i+1]-invx[i]);
    for (int i=1;i<=C;i++) add_edge(R+i,t,invy[i+1]-invy[i]);
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++) if (mp[i][j])
            add_edge(i,R+j,inf);
    printf("%d\n",dinic());
    return 0;
}