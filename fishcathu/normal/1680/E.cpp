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
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[2][N],f[2][N];
void solve()
{
    int n=read();
    for(int i=0;i<=1;++i)for(int j=1;j<=n;++j)a[i][j]=read<char>()=='*';
    int l=1,r=n;
    while(!a[0][l]&&!a[1][l])++l;
    while(!a[0][r]&&!a[1][r])--r;
    f[0][l-1]=f[1][l-1]=-1;
    for(int i=l;i<=r;++i)
    {
        f[0][i]=min(f[0][i-1]+1+a[1][i],f[1][i-1]+2);
        f[1][i]=min(f[1][i-1]+1+a[0][i],f[0][i-1]+2);
    }
    cout<<min(f[0][r],f[1][r])<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}