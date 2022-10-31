// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const int MAXN=35000005;
bool pr[MAXN];
int _p[MAXN>>3],_pos;
void sieve()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i]) _p[++_pos]=i;
		for(int j=1;j<=_pos&&i*_p[j]<MAXN;++j)
		{
			pr[i*_p[j]]=true;
			if(!(i%_p[j])) break;
		}
	}
}
ll t[N],a[55];
ll X[55],Y[55];
ll dis[55][N],M[55];
bool inq[N];
int _q[N<<6],_l,_r;
ll _n[N],_k[N];
void exgcd(__int128 &x,__int128 &y,__int128 a,__int128 b)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(y,x,b,a%b);
	y-=(a/b)*x;
}
int main()
{
	sieve();
	int _;read(_);
	ll n,k;
	int p=0;
	for(int i=1;i<=_;++i)
	{
		read(n,k);
		_n[i]=n,_k[i]=k;
		t[++p]=k;
	}
	std::sort(t+1,t+p+1);
	p=std::unique(t+1,t+p+1)-t-1;
	for(int __=1;__<=p;++__)
	{
		k=t[__];
		int pos=0;
		for(int j=1;j<=_pos&&1ll*_p[j]*_p[j]<=k;++j)
		{
			ll i=_p[j];
			if(!(k%i))
			{
				a[++pos]=i;
				while(!(k%i)) k/=i;
			}
		}
		if(k>1) a[++pos]=k;
		std::sort(a+1,a+pos+1);
		pos=std::unique(a+1,a+pos+1)-a-1;
		if(!pos) X[__]=1;
		else if(pos==1) X[__]=a[1];
		else if(pos==2) X[__]=a[1],Y[__]=a[2];
		else
		{
			memset(inq,0,sizeof(inq));
			memset(dis[__],63,sizeof(dis[__]));
			dis[__][0]=0;
			_q[_l=_r=1]=0;
			M[__]=a[1];
			while(_l!=_r+1)
			{
				int x=_q[_l++];
				inq[x]=false;
				for(int i=2;i<=pos;++i)
				{
					ll val=dis[__][x]+(x+a[i])/a[1];
					int to=(x+a[i])%a[1];
					if(dis[__][to]>val)
					{
						dis[__][to]=val;
						if(!inq[to]) inq[to]=true,_q[++_r]=to;
					}
				}
			}
		}
	}
	for(int i=1;i<=_;++i)
	{
		n=_n[i],k=_k[i];
		if(k==1)
		{
			puts("NO");
			continue;
		}
		int pos=std::lower_bound(t+1,t+p+1,k)-t;
		if(X[pos])
		{
			if(Y[pos])
			{
				__int128 x,y;
				exgcd(x,y,X[pos],Y[pos]);
				x*=(__int128)n,y*=(__int128)n;
				if(x>=0&&y>=0) puts("YES");
				else if(x<0&&y<0) puts("NO");
				else if(x<0)
				{
					__int128 tmp=(-x+Y[pos]-1)/Y[pos];
					if(y>=(__int128)tmp*X[pos]) puts("YES");
					else puts("NO");
				}
				else
				{
					__int128 tmp=(-y+X[pos]-1)/X[pos];
					if(x>=(__int128)tmp*Y[pos]) puts("YES");
					else puts("NO");
				}
			}
			else
			{
				if(!(n%k)) puts("YES");
				else puts("NO");
			}
		}
		else
		{
			ll minn=dis[pos][n%M[pos]]*M[pos]+n%M[pos];
			if(n>=minn) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}