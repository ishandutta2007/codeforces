#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef unsigned long long ull;
int hmt()
{
    int x=0;
    int c=getchar(),n=0;
    for(; !isdigit(c); c=getchar())
        n=(c=='-');
    for(; isdigit(c); c=getchar())
        x=x*10+c-'0';
    if(n)
        x=-x;
    return x;
}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=3010,mod=998244353;
int m,n,f[N][N];
string s,t;
ull pw[N],a[N];
void Enter()
{
    cin>>s>>t;
    n=s.size(), reverse(all(s)), s=" "+s;
    m=t.size(), t=" "+t;
}
void QHD()
{
    forinc(i,m+1,n+1) f[0][i]=1;
    forinc(i,1,n)
    {
        forinc(l,0,n)
        {
            int r=l+n-i+2;
            if(!f[l][r])
                continue;
            if(i==n)
            {
                if(l>=m)
                {
                    f[l+1][r]=(f[l+1][r]+f[l][r])%mod;
                }
                else
                {
                    if(s[i]==t[l+1])
                        f[l+1][r]=(f[l+1][r]+f[l][r])%mod;
                }
                continue;
            }
            if(l>=m)
            {
                f[l+1][r]=(f[l+1][r]+f[l][r])%mod;
                f[l][r-1]=(f[l][r-1]+f[l][r])%mod;
                continue;
            }
            if(s[i]==t[l+1])
                f[l+1][r]=(f[l+1][r]+f[l][r])%mod;
            if(r-1<=m && s[i]==t[r-1])
                f[l][r-1]=(f[l][r-1]+f[l][r])%mod;
            if(r-1>m)
                f[l][r-1]=(f[l][r-1]+f[l][r])%mod;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("baiC.inp","r",stdin);
    Enter();
    pw[0]=1;
    forinc(i,1,n) pw[i]=pw[i-1]*47%mod;
    forinc(i,1,n) a[i]=(a[i-1]*47+s[i])%mod;
    QHD();
    int ans=0;
    forinc(i,0,n) ans=(ans+f[i][i+1])%mod;
    cout<<ans*2%mod;
}