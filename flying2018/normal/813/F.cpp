#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define N 100010
using namespace std;
int f[N],dis[N],siz[N],n;
int find(int &x){int d=0;for(;f[x]!=x;x=f[x]) d^=dis[x];return d;}
int tx[N],ty[N],tn;
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
vector<P >v[N<<2];
void insert(int u,int l,int r,int L,int R,P b)
{
    if(L<=l && r<=R){v[u].push_back(b);return;}
    int mid=(l+r)>>1;
    if(L<=mid) insert(u<<1,l,mid,L,R,b);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,b);
}
void answer(int u,int l,int r)
{
    int sp=tn;
    bool can=true;
    for(auto x:v[u])
        if(!merge(x.fi,x.se)){can=false;break;}
    if(!can){back(sp);for(int i=l;i<=r;i++) puts("NO");return;}
    if(l==r){puts("YES");return;}
    int mid=(l+r)>>1;
    answer(u<<1,l,mid),answer(u<<1|1,mid+1,r);
    back(sp);
}
map<P,int>s;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++)
    {
        P a;
        scanf("%d%d",&a.fi,&a.se);
        if(s.count(a)) insert(1,1,m,s[a],i-1,a),s.erase(a);
        else s[a]=i;
    }
    for(auto x:s)insert(1,1,m,x.se,m,x.fi);
    answer(1,1,m);
    return 0;
}