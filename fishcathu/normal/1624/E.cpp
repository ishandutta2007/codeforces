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
const int N=1010;
const int inf=1<<30;
map<string,array<int,3>>f;
string a;
int pre[N];
void dfs(int n,int s)
{
    if(!n)cout<<s<<'\n';
    else
    {
        dfs(pre[n],s+1);
        for(int x:f[a.substr(pre[n],n-pre[n])])cout<<x<<' ';
        cout<<'\n';
    }
}
void solve()
{
    int n=read(),m=read();
    f.clear();
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        for(int j=2;j<=m;++j)
        {
            f[a.substr(j-2,2)]={j-1,j,i};
            if(j^2)f[a.substr(j-3,3)]={j-2,j,i};
        }
    }
    cin>>a;
    for(int i=1;i<=m;++i)pre[i]=-1;
    for(int i=2;i<=m;++i)
    {
        if(~pre[i-2]&&f.count(a.substr(i-2,2)))pre[i]=i-2;
        else if(i^2&&~pre[i-3]&&f.count(a.substr(i-3,3)))pre[i]=i-3;
    }
    if(~pre[m])dfs(m,0);
    else cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}