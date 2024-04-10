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
const int N=260;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],f[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=a[i-1]+read();
    for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)f[i][j]=inf;
    f[0][0]=0;
    for(int x=m;x>=0;--x)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=x;j<=m;++j)
            {
                cmin(f[i][j],f[i-1][j-x]+abs(j-a[i]));
            }
        }
    }
    cout<<f[n][m]<<'\n';
}