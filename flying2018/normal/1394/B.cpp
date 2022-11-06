#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 200010
#define ll long long
#define P pair<ll,ll>
#define MP make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;
P operator +(const P a,const P b){return MP((a.fi+b.fi)%mod,(a.se+b.se)%mod);}
P operator +(const P a,const int b){return MP((a.fi+b)%mod,(a.se+b)%mod);}
P operator -(const P a,const P b){return MP((a.fi-b.fi+mod)%mod,(a.se-b.se+mod)%mod);}
P operator *(const P a,const P b){return MP((a.fi*b.fi)%mod,(a.se*b.se)%mod);}
const P bs=MP(233333,2333333);
P h[N],all;
struct node{
    int v,w;
    bool operator <(const node a)const{return w<a.w;}
};
vector<node>r[N];
int k;
ll ans=0;
P s[11][11];
void dfs(int u,P hs)
{
    if(u>k){ans+=hs==all;return;}
    for(int i=0;i<u;i++)
    {
        P v=hs+s[u][i];
        dfs(u+1,v);
    }
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&k);
    h[0]=MP(1,1);
    for(int i=1;i<=n;i++) h[i]=h[i-1]*bs,all=all+h[i];
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        r[u].push_back((node){v,w});
    }
    for(int i=1;i<=n;i++)
    {
        sort(r[i].begin(),r[i].end());
        int p=r[i].size();
        for(int j=0;j<p;j++) s[p][j]=s[p][j]+h[r[i][j].v];
    }
    dfs(1,MP(0,0));
    printf("%lld\n",ans);
    return 0;
}