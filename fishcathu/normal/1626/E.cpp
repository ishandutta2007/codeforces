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
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
const int N=3E5+10;
const int inf=1<<30;
vector<int>to[N];
int n,m;
bool a[N],b[N],c[N];
void init(int x,int f)
{
    a[x]=1;
    for(int t:to[x])if(t^f&&!b[t])init(t,x);
}
void output()
{
    for(int i=1;i<=n;++i)cout<<!a[i]<<' ';
    cout<<'\n';
    exit(0);
}
int dfs(int x,int f,bool d)
{
    int s=0;
    for(int t:to[x])if(t^f)s+=dfs(t,x,d|b[x]);
    if(b[x])return 1;
    if(s+d^m)return s;
    init(x,0);
    output();
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for(int i=1;i<=n;++i)m+=c[i]=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    for(int i=1;i<=n;++i)if(c[i])
    {
        b[i]=1;
        for(int j:to[i])b[j]=1;
    }
    dfs(1,0,0);
    output();
}