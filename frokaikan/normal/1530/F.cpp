#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1<<21;
const int inf = 0x3f3f3f3f;
const int mod = 31607;

//header
ll qp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int a[25][25],ia[25][25];

void ifwt(vi& a)
{
    int N=a.size();
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p) rep(k,0,i-1) chsub(a[j+k],a[i+j+k]);
}

int b[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) rep(j,1,n) scanf("%d",&a[i][j]),a[i][j]=a[i][j]*qp(10000,mod-2)%mod;
    rep(i,1,n) rep(j,1,n) ia[i][j]=(1-a[i][j]+mod)%mod;
    int ans=0,ps=1;
    rep(i,1,n)
    {
        ll tmp=1;
        rep(j,1,n) tmp=tmp*a[i][j]%mod;
        ans=(ans+ps*tmp)%mod;
        ps=ps*(1-tmp+mod)%mod;
    }
    int N=1<<(n+2);
    vi res(N,1);
    rep(i,1,n)
    {
        int B=1<<n;
        int tmp=1;
        rep(j,1,n) tmp=tmp*a[i][j]%mod;
        b[0]=1;
        rep(msk,1,B-1)
        {
            int last=__builtin_ctz(msk);
            b[msk]=b[msk^(1<<last)]*a[i][last+1]%mod;
        }
        rep(msk,0,B-1) chsub(b[msk],tmp);
        vi A(N,0);
        rep(msk,0,B-1) 
        {
            per(d,0,1) per(ad,0,1) A[msk|(d<<n)|(ad<<(n+1))]=b[msk|(d<<(i-1))|(ad<<(n-i))];
        }
        rep(j,0,N-1) res[j]=res[j]*A[j]%mod;
    }
    ifwt(res);
    rep(msk,1,N-1) ans=(ans+res[msk])%mod;
    printf("%d\n",ans);
	return 0;
}