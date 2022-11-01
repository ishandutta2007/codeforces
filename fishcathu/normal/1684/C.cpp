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
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

void solve()
{
    int m=read(),n=read();
    vector<vector<int>>a(n,vector<int>(m));
    for(int j=0;j<m;++j)for(int i=0;i<n;++i)cin>>a[i][j];
    vector<vector<int>>b=a;
    sort(b.begin(),b.end());
    for(int i=1;i<n;++i)for(int j=0;j<m;++j)if(b[i][j]<b[i-1][j])return cout<<"-1\n",void();
    vector<int>q;
    for(int i=0;i<n;++i)if(a[i]!=b[i])q.pb(i+1);
    if(q.empty())cout<<"1 1\n";
    else if(q.size()>2)cout<<"-1\n";
    else cout<<q[0]<<' '<<q[1]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}