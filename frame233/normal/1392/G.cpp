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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=(1<<20)+5;
int S[N],T[N];
int mark[N];
std::vector<int> e[N];
int dis[N];
int _q[N],_l,_r;
int X[N],Y[N];
int p[25];
int main()
{
	int n,m,k;read(n,m,k);
	int s=0,t=0,x,y;
	for(int i=0;i<k;++i) scanf("%1d",&x),s|=x<<i;
	for(int i=0;i<k;++i) scanf("%1d",&x),t|=x<<i;
	S[0]=s,T[0]=t;
	for(int i=0;i<k;++i) p[i]=i;
	for(int i=1;i<=n;++i)
	{
		read(x,y);--x,--y;
		for(int j=0;j<k;++j)
		{
			if(p[j]==x) p[j]=y;
			else if(p[j]==y) p[j]=x;
		}
		int st=0;
		for(int j=0;j<k;++j) st|=((s>>p[j])&1)<<j;
		S[i]=st,st=0;
		for(int j=0;j<k;++j) st|=((t>>p[j])&1)<<j;
		T[i]=st;
	}
	memset(mark,255,sizeof(mark));
	memset(dis,63,sizeof(dis));
	int ans=inf,A=0,B=0;
	for(int i=0;i<=n-m;++i)
	{
		mark[S[i]]=i+1;
		_q[_l=_r=1]=S[i];
		dis[S[i]]=0;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=0;i<k;++i)
			{
				int v=x^(1<<i);
				if(dis[v]>dis[x]+1) dis[v]=dis[x]+1,mark[v]=mark[x],_q[++_r]=v;
			}
		}
		int nd=T[i+m];
		if(dis[nd]<ans)
		{
			ans=dis[nd];
			A=mark[nd],B=i+m;
		}
	}
	printf("%d\n%d %d\n",k-ans,A,B);
	return 0;
}