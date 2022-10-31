// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
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

const int N=600005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int n,l1,l2;
char s[N],t[N];
ll fac[N],inv[N],ifac[N],pw[N];
bool pr[N];
int p[N],pos,mu[N],___;
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	pw[0]=1,pw[1]=2;
	for(int i=2;i<N;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
		pw[i]=pw[i-1],add(pw[i],pw[i]);
	}
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!pr[i]) p[++pos]=i,mu[i]=-1;
		for(int j=1;j<=pos&&1ll*i*p[j]<N;++j)
		{
			pr[i*p[j]]=true;
			if(!(i%p[j]))
			{
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int g=1;g<=n;++g)
	{
		ll tmp=0;
		for(int d=1;d*g<=n;++d) tmp+=1ll*mu[d]*(n/(d*g))*(n/(d*g))%mod;
		tmp%=mod,tmp+=mod;
		add(___,1ll*tmp*pw[g]%mod);
	}
}
Finline ll C(int n,int m)
{
	if(n<m||m<0) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll f(int a,int b)
{
	if(!a&&!b) return ___;
	if(1ll*a*b>=0) return 0;
	a=abs(a),b=abs(b);
	return pw[n/(max(a,b)/gcd(a,b))+1]-2;
}
int main()
{
	l1=read_str(s+1);
	l2=read_str(t+1);
	read(n);
	init();
	int ans=0,qwq=0;
	if(l1==l2)
	{
		for(int i=1;i<=l1;++i)
		{
			if(s[i]=='?'&&t[i]=='?') ++qwq;
			else if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i]){qwq=-1;break;}
		}
		if(qwq>=0) qwq=pw[qwq],add(ans,1ll*qwq*(pw[n+1]+mod-2)%mod*(pw[n+1]+mod-2)%mod);
		else qwq=0;
	}
	int Da=0,Db=0,Ca=0,Cb=0;
	for(int i=1;i<=l1;++i) Da+=s[i]=='A',Db+=s[i]=='B',Ca+=s[i]=='?';
	for(int i=1;i<=l2;++i) Da-=t[i]=='A',Db-=t[i]=='B',Cb+=t[i]=='?';
	Db+=Ca-Cb;
	for(int d=-Cb;d<=Ca;++d)
	{
		int da=Da+d,db=Db-d;
		ll cnt=C(Ca+Cb,Cb+d);
		if(!da&&!db) add(ans,1ll*(cnt-qwq+mod)*___%mod);
		else add(ans,1ll*cnt*f(da,db)%mod);
	}
	printf("%d\n",ans);
	return 0;
}