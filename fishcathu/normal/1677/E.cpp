#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=2E5+10;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],pos[N],q[N],s;
ll A[N],B[N],C[N],D[N],ans[N*5];
vector<int>to[N];
vector<pii>st[N],qry[N];
void init(int i,int l,int r)
{
    vector<pii>q;
    for(int x:to[a[i]])
    {
        int u=pos[x],v=pos[a[i]/x];
        if(u>v)swap(u,v);
        if(u>=l&&v<=r)q.pb({min(u,i),max(v,i)});
    }
    if(q.empty())return;
    sort(q.begin(),q.end(),[](pii x,pii y){return x[1]^y[1]?x[1]<y[1]:x[0]>y[0];});
    int t=l-1;
    for(auto [x,y]:q)if(x>t)
    {
        st[y].pb({x,1});
        st[y].pb({t,-1});
        t=x;
    }
    st[r+1].pb({l-1,1});
    st[r+1].pb({t,-1});
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        pos[a[i]=read()]=i;
        for(int j=min(i-1,n/i)*i;j;j-=i)to[j].pb(i);
    }
    for(int i=1;i<=n;++i)
    {
        while(s&&a[q[s]]<a[i])init(q[s],q[s-1]+1,i-1),--s;
        q[++s]=i;
    }
    while(s)init(q[s],q[s-1]+1,n),--s;
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        qry[r].pb({l,i});
    }
    for(int j=1;j<=n;++j)
    {
        for(auto [i,a]:st[j])
        {
            ll b=a*i,c=a*j,d=1LL*a*i*j;
            for(;i;i-=i&-i)
            {
                A[i]+=a;
                B[i]+=b;
                C[i]+=c;
                D[i]+=d;
            }
        }
        for(auto [i,id]:qry[j])
        {
            ll a=0,b=0,c=0,d=0;
            for(int k=i;k<=j;k+=k&-k)
            {
                a+=A[k];
                b+=B[k];
                c+=C[k];
                d+=D[k];
            }
            ans[id]=b*(j+1)+c*(i-1)-a*(i-1)*(j+1)-d;
        }
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<'\n';
}