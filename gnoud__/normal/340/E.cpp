#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
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
const int N=2100,mod=1e9+7;
int n,f[N][N],dd[N],a[N],pw[N];
int C(int n,int k)
{
    if(!k||n==k) return 1;
    if(f[n][k]!=-1) return f[n][k];
    return f[n][k]=(C(n-1,k)+C(n-1,k-1))%mod;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    reset(f,-1);
    cin>>n;
    pw[0]=1;
    forinc(i,1,n) pw[i]=pw[i-1]*i%mod;
    forinc(i,1,n)
    {
        cin>>a[i];
        dd[a[i]]=1;
    }
    int m=0,k=0;
    forinc(i,1,n) if(a[i]==-1)
    {
        m++;
        if(!dd[i]) ++k;
    }
    int ans=0;
    forinc(i,0,k) ans=(ans+C(k,i)*pw[m-i]*((i%2)?-1:1))%mod;
    cout<<(ans+mod)%mod<<"\n";
}