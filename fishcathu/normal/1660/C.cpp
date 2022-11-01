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
const int N=2E5+10,M=27;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

char a[N];
int f[N][M];
void solve()
{
    cin>>a+1;
    int n=strlen(a+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<M;++j)f[i][j]=f[i-1][j]+1;
        cmin(f[i][0],f[i-1][a[i]-96]);
        cmin(f[i][a[i]-96],f[i-1][0]);
    }
    cout<<f[n][0]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int i=1;i<M;++i)f[0][i]=inf;
    for(int T=read();T--;solve());
}