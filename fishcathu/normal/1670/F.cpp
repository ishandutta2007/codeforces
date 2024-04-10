#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1010;
template<typename T=int>T read(){T x;cin>>x;return x;}

const int p=1E9+7;
int c[N][N],f[61][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=0;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    }
    ll l=read<ll>(),r=read<ll>(),m=read<ll>();
    f[60][0]=1;
    auto calc=[&](ll x)
    {
        for(int k=60;k--;)
        {
            for(int i=0;i<=n;++i)
            {
                f[k][i]=0;
                for(int j=m>>k&1;j<=n;j+=2)
                {
                    f[k][i]=(f[k][i]+1LL*f[k+1][i+j+(~x>>k&1)>>1]*c[n][j])%p;
                }
            }
        }
        return f[0][0];
    };
    cout<<(calc(r)-calc(l-1)+p)%p<<'\n';
}