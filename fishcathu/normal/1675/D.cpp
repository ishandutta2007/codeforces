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

int fa[N];
bool a[N],b[N];
void dfs(int x,int s)
{
    if(b[x])cout<<s<<'\n';
    else
    {
        b[x]=1;
        dfs(fa[x],s+1);
        cout<<x<<' ';
    }
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        cin>>fa[i];
        a[fa[i]]=1;
        b[i]=0;
    }
    if(n==1)a[1]=0;
    cout<<count(a+1,a+1+n,0)<<'\n';
    for(int i=1;i<=n;++i)
    {
        if(a[i])a[i]=0;
        else dfs(i,0),cout<<'\n';
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}