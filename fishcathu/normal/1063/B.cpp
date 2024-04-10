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
const int N=2010;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N][N],vis[N][N];
deque<array<int,4>>q;
void ins(int i,int j,int l,int r,int k)
{
    if(!a[i][j]||vis[i][j]||!~l||!~r)return;
    vis[i][j]=1;
    if(k)q.push_back({i,j,l,r});
    else q.push_front({i,j,l,r});
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read(),x=read(),y=read(),u=read(),v=read();
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=read<char>()=='.';
    int ans=0;
    ins(x,y,u,v,0);
    while(!q.empty())
    {
        auto [i,j,l,r]=q.front();
        q.pop_front();
        ins(i-1,j,l,r,0);
        ins(i+1,j,l,r,0);
        ins(i,j-1,l-1,r,1);
        ins(i,j+1,l,r-1,1);
        ++ans;
    }
    cout<<ans<<'\n';
}