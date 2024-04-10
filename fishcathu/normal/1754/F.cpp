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
constexpr int N=2E5+10;
constexpr ll inf=1E18;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int to[4][2]={0,1,0,-1,1,0,-1,0},h[86];
struct node{int x=-1;ll dis;};
struct st{int i,j;ll x;bool operator<(const st t)const{return x>t.x;}};
priority_queue<st>q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int i=0;i<6;++i)h["LRUD.#"[i]]=i;
    int n=read(),m=read(),w[2]={read(),read()};
    vector<vector<node>>a(n+2,vector<node>(m+2));
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
    {
        int x=h[read<char>()];
        if(x<4)a[i][j]={x,inf};
        else if(x==4)a[i][j].x=4,q.push({i,j,0});
    }
    while(!q.empty())
    {
        auto [i,j,x]=q.top();
        q.pop();
        if(x^a[i][j].dis)continue;
        for(int k=0;k<4;++k)
        {
            int l=i+to[k][0],r=j+to[k][1],y=a[l][r].x;
            if(~y&&y<4&&k^y^1&&cmin(a[l+=to[y][0]][r+=to[y][1]].dis,x+w[k==y]))q.push({l,r,a[l][r].dis});
        }
    }
    ll mn=inf;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(~a[i][j].x)
    {
        if(~a[i][j+1].x)cmin(mn,a[i][j].dis+a[i][j+1].dis);
        if(~a[i+1][j].x)cmin(mn,a[i][j].dis+a[i+1][j].dis);
    }
    cout<<(mn^inf?mn:-1)<<'\n';
}