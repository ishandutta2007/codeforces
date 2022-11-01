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
const int N=1010;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

const pii nex[4]={0,1,0,-1,1,0,-1,0};
int a[N][N],dis[N][N][3];
pii b[3];
deque<pii>q;
void ins(int i,int j,int k,int x)
{
    if(!~a[i][j]||!cmin(dis[i][j][k],x+a[i][j]))return;
    if(a[i][j])q.push_back({i,j});
    else q.push_front({i,j});
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    memset(a,-1,sizeof a);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
    {
        char x=read<char>();
        if(x=='.')a[i][j]=1;
        else if(x^'#')b[x-49]={i,j},a[i][j]=0;
        for(int k=0;k<3;++k)dis[i][j][k]=inf;
    }
    for(int k=0;k<3;++k)
    {
        ins(b[k][0],b[k][1],k,0);
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop_front();
            for(auto [x,y]:nex)ins(i+x,j+y,k,dis[i][j][k]);
        }
    }
    int ans=inf;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(~a[i][j])
    {
        ll res=0LL+dis[i][j][0]+dis[i][j][1]+dis[i][j][2]-a[i][j]*2;
        cmin(ans,res);
    }
    cout<<(ans^inf?ans:-1)<<'\n';
}