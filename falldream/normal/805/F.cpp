#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define ld long double
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define MN 100000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

map<ll,double> mp;
vector<int> v[MN+5];
int head[MN+5],mx[MN+5],mx2[MN+5],from[MN+5],F[MN+5],f[MN+5],cnt=0,n,m,q,bel[MN+5],tot=0,rt[MN+5];
struct edge{int to,next;}e[MN*2+5];
bool mark[MN+5];

inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}

void Dp(int x,int fa)
{
    mark[x]=1;bel[x]=tot;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            Dp(e[i].to,x);int val=mx[e[i].to]+1;
            F[x]=max(F[x],F[e[i].to]);
            if(val>mx[x]) mx2[x]=mx[x],mx[x]=val,from[x]=e[i].to;
            else if(val>mx2[x]) mx2[x]=val;
        }
    F[x]=max(F[x],mx[x]+mx2[x]);
}
inline void R(int&a,int&b,int&c,int d){if(d>=a)c=a,a=d,b=0;else if(d>=c)c=d;}
void Solve(int x,int fa)
{
    v[bel[x]].push_back(mx[x]);
 //   cout<<"Solve"<<x<<" "<<mx[x]<<" "<<mx2[x]<<endl;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            R(mx[e[i].to],from[e[i].to],mx2[e[i].to],(e[i].to==from[x]?mx2[x]:mx[x])+1);
            Solve(e[i].to,x);
        }
}

void Calc(int x,int y)
{
    x=bel[x];y=bel[y];int Mx=max(F[rt[x]],F[rt[y]]);
    if(v[x].size()>v[y].size()) swap(x,y);
    ll ans=0;ll Tot=0,k=v[y][v[y].size()-1]+1;
        for(int i=0,j=v[y].size()-1;i<v[x].size();++i)
    {
        while(j>0&&v[y][j-1]+v[x][i]+1>=Mx) k+=v[y][--j]+1;
        if(v[x][i]+v[y][j]+1>=Mx)
        {
            Tot+=v[y].size()-j;
            ans+=(ld)k+1LL*(v[y].size()-j)*v[x][i];
        }
    }
    ll sz=1LL*v[x].size()*v[y].size();
    ans+=(sz-Tot)*Mx;
    if(x>y) swap(x,y);
    ll ha=1LL*x*(tot+1)+y;
    printf("%.8lf\n",mp[ha]=(double)ans/sz);
}

bool check(int x,int y)
{
    x=bel[x],y=bel[y];if(x>y) swap(x,y);
    ll ha=1LL*x*(tot+1)+y;
    if(mp[ha]>0) return printf("%.8lf\n",(double)mp[ha]),true;
    return false;
}

int main()
{
    n=read();m=read();q=read();
    for(int i=1;i<=m;++i)
        ins(read(),read());
    for(int i=1;i<=n;++i) if(!mark[i])
        Dp(rt[++tot]=i,0);
    for(int i=1;i<=tot;++i)
        Solve(rt[i],0),sort(v[i].begin(),v[i].end());
    for(int i=1;i<=q;++i)
    {
        int x=read(),y=read();
        if(bel[x]==bel[y]) puts("-1");
        else if(!check(x,y)) Calc(x,y);
    }
    return 0;
}