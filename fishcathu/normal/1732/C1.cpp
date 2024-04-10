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
constexpr int N=1E5+10,M=30;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int f[N][M];
vector<int>to[M];
void solve()
{
    int n=read(),m=read();
    for(int i=0;i<M;++i)to[i].clear();
    for(int i=1;i<=n;++i)
    {
        int x=read();
        for(int j=0;j<M;++j)
        {
            if(x>>j&1)f[i][j]=f[i-1][j]+1,to[j].pb(i);
            else f[i][j]=f[i-1][j];
        }
    }
    while(m--)
    {
        int l=read(),r=read(),c=0,d=n;
        vector<pii>q;
        for(int i=0;i<M;++i)
        {
            int u=f[l-1][i],v=f[r][i]-1;
            if(u>=v)continue;
            if(v-u&1)cmax(c,to[i][v]),cmin(d,to[i][u]);
            else cmax(c,to[i][v-1]),q.pb({to[i][u],to[i][v]}),cmin(d,to[i][u+1]);
        }
        if(!c)cout<<l<<' '<<l<<'\n';
        else
        {
            q.pb({d,inf});
            int u,v,mn=inf;
            sort(q.begin(),q.end(),[](pii x,pii y){return x[0]<y[0];});
            for(auto [x,y]:q)
            {
                if(cmin(mn,c-x))u=x,v=c;
                cmax(c,y);
            }
            cout<<u<<' '<<v<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}