//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n;
ll a[111];
ll k,ans;
int v[10000000],vv[10000000];
int sz;
int rec[111],recv[111],tmp[111];

const int msk=255;
const int times=2;
const int bitsz=16;
const int sortbase=0;
int na[10000000],naa[10000000],b[msk+1];
void kotori_sort(int a[],int aa[],int n)
{
	for(int i=1;i<=n;i++)a[i]+=sortbase;
	for(int tt=0;tt<times;tt++)
	{
		memset(b,0,sizeof(b));
		int tmp=tt*bitsz;
		for(int i=1;i<=n;i++)b[(a[i]>>tmp)&msk]++;
		for(int i=1;i<=msk;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)
		{
			int x=(a[i]>>tmp)&msk;
			naa[b[x]]=aa[i];
			na[b[x]--]=a[i];
		}
		memset(b,0,sizeof(b));
		tmp=tt*bitsz+bitsz/2;
		for(int i=1;i<=n;i++)b[(na[i]>>tmp)&msk]++;
		for(int i=1;i<=msk;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)
		{
			int x=(na[i]>>tmp)&msk;
			aa[b[x]]=naa[i];
			a[b[x]--]=na[i];
		}
	}
	for(int i=1;i<=n;i++)a[i]-=sortbase;
}

int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
//	n=100;k=1e11;
//	for(int i=1;i<=n;i++)a[i]=1e9-rand();
	for(int i=1;i<=n;i++)a[i]--;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll l=1,r;
		while(l<=a[i])
		{
			r=a[i]/(a[i]/l);
			v[++sz]=l;
			vv[sz]=i;
			l=r+1;
		}
		v[++sz]=a[i]+1;
		vv[sz]=i;
	}
	kotori_sort(v,vv,sz);
//	for(int i=1;i<=sz;i++)cout<<v[i]<<" ";cout<<endl;	
//	for(int i=1;i<=sz;i++)cout<<vv[i]<<" ";cout<<endl;
	ll sp=0,sum=0;
	for(int i=1;i<=sz;i++)
	{
		int id=vv[i];
		ll nxt;
		if(i==sz)nxt=2ll*mod*233;
		else nxt=v[i+1];
		sum-=tmp[id];
		tmp[id]=v[i]-a[id]%v[i]-1;
		sum+=tmp[id];
		sum-=(v[i]-rec[id])*recv[id];
		rec[id]=v[i];
		sp-=recv[id];
		recv[id]=a[id]/v[i]+1;
		sp+=recv[id];
		if(sum<=k)
		{
			ll d=min((k-sum)/sp+v[i],nxt-1);
			if(d>=v[i])
			{
				ans=max(ans,d);
			}
		}
		sum+=(nxt-v[i])*sp;
	}
	cout<<ans<<endl;
	return 0;
}