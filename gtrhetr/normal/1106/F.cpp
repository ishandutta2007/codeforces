#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define md 100007

struct node { ll x,y,next; }a[1000010];

ll head[100010],num[110],n,m,k,sq,tot;

struct matrix
{
	ll a[110][110];
	matrix() { memset(a,0,sizeof(a)); }
};

inline ll pls(const ll x,const ll y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll pls1(const ll x,const ll y) { return (x+y<(mod-1))?x+y:x+y-(mod-1); }
inline ll mns(const ll x,const ll y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline matrix operator *(const matrix x,const matrix y)
{
	matrix res;
	for (int i=1;i<=k;i++) for (int j=1;j<=k;j++) for (int l=1;l<=k;l++) res.a[i][j]=pls1(res.a[i][j],x.a[i][l]*y.a[l][j]%(mod-1));
	return res;
}

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline matrix ksm1(matrix x,ll y)
{
	matrix res;
	for (int i=1;i<=k;i++) res.a[i][i]=1;
	for (;y;y>>=1,x=x*x) if (y&1) res=res*x;
	return res;
}

inline void add(ll x,ll y)
{
    for (ll i=head[x%md];i;i=a[i].next) if (a[i].x==x) { a[i].y=y;return; }
    a[++tot].x=x;a[tot].y=y;a[tot].next=head[x%md];head[x%md]=tot;
}

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) { x=1;y=0;return; }
	ex_gcd(b,a%b,x,y);
	ll hh=x;x=y;y=hh-y*(a/b);
}

inline ll getinv(ll a,ll b)
{
	ll x,y;
	ex_gcd(a,b,x,y);
	return (x%b+b)%b;
}

int main()
{
	k=rd();
	for (int i=1;i<=k;i++) num[i]=rd()%(mod-1);
	n=rd();m=rd();
	matrix h1;
	for (int i=1;i<k;i++) h1.a[i+1][i]=1;
	for (int i=1;i<=k;i++) h1.a[i][k]=num[k-i+1];
	h1=ksm1(h1,n-k);
	matrix fir;
	fir.a[1][k]=1;
	fir=fir*h1;
	ll now=fir.a[1][k];
	sq=(ll)sqrt(mod)+1;
	ll hhh=ksm(3,sq);
    ll hh=m;tot=0;
    for (int i=1;i<=sq;i++) { hh=hh*3%mod;add(hh,i); }
    ll res=mod+1;hh=1LL;
    for (int i=1;i<=sq;i++)
    {
        hh=hh*hhh%mod;
        for (int j=head[hh%md];j;j=a[j].next) if (a[j].x==hh) { res=min(res,i*sq-a[j].y);break; }
    }
    if (!res&&!now)
    {
    	puts("1");
    	return 0;
	}
	if (!res)
	{
		puts("1");
		return 0;
	}
	if (!now) { puts("-1");return 0; }
	hhh=gcd(res,now);
	res/=hhh;now/=hhh;
	hhh=gcd(now,mod-1);
	if (hhh!=1) { puts("-1");return 0; }
	ll hhhh=getinv(now,mod-1);
	printf("%I64d\n",ksm(3,res*hhhh%(mod-1)));
	return 0;
}