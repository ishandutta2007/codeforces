#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MOD=1e9+7;
const LL MAXN=5e5+10;
inline LL Pow(LL x,LL y)
{
    LL ans=1;
    while(y>0)
    {
        if(y&1)
            ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
inline LL inv(LL x)
{
    return Pow(x,MOD-2);
}
LL pa[MAXN];
LL par(LL x)
{
    if(pa[x]<0)
        return x;
    return pa[x]=par(pa[x]);
}
LL cnt;
inline void uni(LL x,LL y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[y]=x;
    cnt--;
    return;
}
LL u[MAXN],v[MAXN],C[MAXN],p2[MAXN];
LL N,M,K,i,j;
LL P,ans;
vector<LL>V;
vector<LL>V2[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
    {
        cin>>C[i];
        pa[i]=-1;
    }
    p2[0]=1;
    for(i=1;i<=N||i<=K;i++)
        p2[i]=p2[i-1]*2%MOD;
    cnt=N;
    for(i=0;i<M;i++)
    {
        cin>>u[i]>>v[i];
        if(C[--u[i]]==C[--v[i]])
            uni(u[i],v[i]);
        else
            V.push_back(C[u[i]]^C[v[i]]);
    }
    P=cnt;
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(i=0;i<M;i++)
    {
        u[i]=par(u[i]);
        v[i]=par(v[i]);
        if(u[i]==v[i])
            continue;
        V2[lower_bound(V.begin(),V.end(),C[u[i]]^C[v[i]])-V.begin()].push_back(i);
    }
    ans=p2[P]*(p2[K]-V.size())%MOD;
    for(i=0;i<V.size();i++)
    {
        cnt=P;
        for(j=0;j<V2[i].size();j++)
            uni(u[V2[i][j]],v[V2[i][j]]);
        for(j=0;j<V2[i].size();j++)
        {
            pa[u[V2[i][j]]]=-1;
            pa[v[V2[i][j]]]=-1;
        }
        ans+=p2[cnt];
    }
    cout<<ans%MOD<<endl;
    return 0;
}