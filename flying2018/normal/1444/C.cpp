#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500010
#define ll long long
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int f[N],dis[N],siz[N],n;
int find(int &x){int d=0;for(;f[x]!=x;x=f[x]) d^=dis[x];return d;}
int tx[N*2],ty[N*2],tn;
bool merge(int x,int y)
{
    int dx=find(x),dy=find(y);
    if(x==y) return dx!=dy;
    if(siz[x]>siz[y]) swap(x,y),swap(dx,dy);
    siz[y]+=siz[x];f[x]=y;
    dis[x]=dx^dy^1;tx[++tn]=x,ty[tn]=y;
    return true;
}
void back(int x){for(;tn>x;tn--) siz[ty[tn]]-=tx[tn],dis[tx[tn]]=0,f[tx[tn]]=tx[tn];}
int id[N];
bool ban[N];
struct road{
    int x,y;
    road(int X=0,int Y=0):x(X),y(Y){}
    bool operator <(const road a)const{return id[x]==id[a.x]?id[y]<id[a.y]:id[x]<id[a.x];}
};
vector<road>r;
bool same(road a,road b){return id[a.x]==id[b.x] && id[a.y]==id[b.y];}
ll ans=0;
int main()
{
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&id[i]);
    for(int i=1;i<=n;i++) siz[i]=1,f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(id[u]>id[v]) swap(u,v);
        if(id[u]==id[v]){if(!merge(u,v)) ban[id[u]]=true;}
        else r.push_back(road(u,v));
    }
    sort(r.begin(),r.end());
    int c=0,bn=0,bk=tn;road p;
    for(int i=1;i<=k;i++) if(!ban[i]) c++;
    ll can=1ll*c*(c-1)/2;
    for(auto u:r)
    {
        // printf("for %d %d\n",u.x,u.y);
        if(!same(u,p))
        {
            if(!ban[id[p.x]] && !ban[id[p.y]]) can-=bn;
            bn=false;
            back(bk);
            p=u;
        }
        else if(bn) continue;
        if(ban[id[u.x]] || ban[id[u.y]]){bn=true;continue;}
        if(!merge(u.x,u.y)){bn=true;continue;}
    }
    // printf("done %d %d\n",lf,rf);
    if(!r.empty() && !ban[id[r.back().x]] && !ban[id[r.back().y]]) can-=bn;
    back(bk);
    printf("%lld\n",can);
    return 0;
}