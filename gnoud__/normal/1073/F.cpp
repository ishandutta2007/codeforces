#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=200010;
int n,x1,x2,x3,x4,it;
int d[N],mx[N],mx2[N];
pii ma1;
vector<int> ad[N];
void dfs(int u,int p)
{
    mx[u]=mx2[u]=0;
    int con=0;
    forv(v,ad[u]) if(v!=p)
    {
        d[v]=d[u]+1;
        dfs(v,u);
        if(!mx[u] || d[mx[v]]>d[mx[u]]) mx2[u]=mx[u],mx[u]=mx[v];
        else if(!mx2[u] || d[mx[v]]>d[mx2[u]]) mx2[u]=mx[v];
        con++;
    }
    if(!con) mx[u]=u;
    if(con>1)
    {
        if(pii(d[u],d[mx[u]]+d[mx2[u]])>ma1)
            ma1={d[u],d[mx[u]]+d[mx2[u]]},it=u;
    }
}
int main()
{
    //freopen(task".inp","r",stdin);
    cin>>n;
    forinc(i,2,n)
    {
        int u,v;
        cin>>u>>v;
        ad[u].pb(v);
        ad[v].pb(u);
    }
    ma1={0,0};
    dfs(1,0);x1=mx[it],x2=mx2[it];
    ma1={0,0};
    d[it]=0;
    dfs(it,0);x3=mx[it],x4=mx2[it];
    cout<<x1<<" "<<x3<<"\n";
    cout<<x2<<" "<<x4<<"\n";
}