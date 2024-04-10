#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=510,mod=1e9+7;
int T,m,l,r,k,S[N][N],C[N][N],jc[N],inv[N];

inline int MOD(int x)
{
	if(x>=mod) x-=mod;
	if(x<0) x+=mod;
	return x;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

struct Node
{
	int x,y,p;
	//=x+sqrt(p)y
	
	Node operator + (const int &l)const{return (Node){MOD(x+l),y,p};}
	Node operator - (const int &l)const{return (Node){MOD(x-l),y,p};}
	Node operator * (const int &l)const{return (Node){x*l%mod,y*l%mod,p};}
	Node operator / (const int &l)const{return (Node){x*q_pow(l,mod-2)%mod,y*q_pow(l,mod-2)%mod,p};}
	
	Node operator + (const Node &l)const{return (Node){MOD(x+l.x),MOD(y+l.y),p};}
	Node operator - (const Node &l)const{return (Node){MOD(x-l.x),MOD(y-l.y),p};}
	Node operator * (const Node &l)const{return (Node){MOD(x*l.x%mod+y*l.y*p%mod),MOD(x*l.y%mod+y*l.x%mod),p};}
	Node operator / (const Node &l)const{
		return (Node){x,y,p}*(Node){l.x,mod-l.y,p}/((l.x*l.x%mod-p*l.y*l.y%mod+mod)%mod);
	}
}A,B,x,y,pwa[N],pwb[N],pwx[N],pwy[N];

inline Node q_pow(Node a,int b)
{
	Node c=(Node){1,0,a.p};
	while(b)
	{
		if(b&1) c=a*c;
		a=a*a;b>>=1;
	}
	return c;
}

inline void init()
{
	jc[0]=1;
	for(int i=1;i<=501;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[501]=q_pow(jc[501],mod-2);
	for(int i=500;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=0;i<=501;++i)
		for(int j=0;j<=i;++j)
			if(j==0) C[i][j]=1,S[i][j]=(i==0);
			else
			{
				C[i][j]=MOD(C[i-1][j]+C[i-1][j-1]);
				S[i][j]=MOD(S[i-1][j]*(i-1)%mod+S[i-1][j-1]);
			}
	pwa[0]=pwb[0]=pwx[0]=pwy[0]=(Node){1,0,m==2?5:3};
	for(int i=1;i<=501;++i)
	{
		pwa[i]=A*pwa[i-1];pwb[i]=B*pwb[i-1];
		pwx[i]=x*pwx[i-1];pwy[i]=y*pwy[i-1];
	}
}

inline Node query(int n,int k)
{
	Node res=(Node){0,0,m==2?5:3};
	for(int i=0;i<=k;++i)
	{
		Node now=(Node){0,0,m==2?5:3};
		for(int j=0;j<=i;++j)
		{
			Node tmp=pwa[j]*pwb[i-j]*C[i][j];
			if((pwx[j]*pwy[i-j]).x==1&&(pwx[j]*pwy[i-j]).y==0) tmp=tmp*((n+1)%mod);
			else tmp=tmp*(q_pow(pwx[j]*pwy[i-j],n+1)-1)/(pwx[j]*pwy[i-j]-1);
			now=now+tmp;
		}
		now=now*S[k][i];
		if((k-i)&1) res=res-now;
		else res=res+now;
	}
	return res*inv[k];
}

signed main()
{
	T=1;m=2;
	A=(Node){0,q_pow(5,mod-2),5};
	B=(Node){0,mod-q_pow(5,mod-2),5};
	x=(Node){q_pow(2,mod-2),q_pow(2,mod-2),5};
	y=(Node){q_pow(2,mod-2),mod-q_pow(2,mod-2),5};
	init();
	while(T--)
	{
		int k=read(),l=read(),r=read();
		int tmp=(query(r+2,k)-query(l+1,k)).x;
		printf("%lld\n",tmp);
	}
	return 0;
}