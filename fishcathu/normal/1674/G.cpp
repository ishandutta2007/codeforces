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
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

vector<int>to[N];
int a[N],in[N],out[N];
void dfs(int x)
{
    if(out[x]<=1)return a[x]=1,void();
    a[x]=0;
    for(int t:to[x])
    {
        if(!~a[t])dfs(t);
        if(in[t]>1)cmax(a[x],a[t]);
    }
    ++a[x];
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1;i<=n;++i)a[i]=-1;
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        ++out[u];
        ++in[v];
    }
    for(int i=1;i<=n;++i)if(!~a[i])dfs(i);
    cout<<*max_element(a+1,a+1+n)<<'\n';
}