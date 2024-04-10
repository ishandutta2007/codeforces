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

const int N=1000005;
int fa[N<<1],len[N][2];
char s[N];
std::vector<int> v1[N],v2[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;read(n);
	read_str(s+1);
	for(int i=1;i<=n+1+n+1;++i) fa[i]=i;
	for(int i=n;i>=1;--i)
	{
		if(s[i]=='?'||s[i]=='0') len[i][0]=len[i+1][0]+1;
		else len[i][0]=0;
		if(s[i]=='?'||s[i]=='1') len[i][1]=len[i+1][1]+1;
		else len[i][1]=0;
		if(len[i][0]) v1[len[i][0]].pb(i);
		else fa[find(i)]=find(i+1);
		if(len[i][1]) v2[len[i][1]].pb(i);
		else fa[find(i+n+1)]=find(i+n+1+1);
	}
	for(int x=1;x<=n;++x)
	{
		for(auto it:v1[x-1]) fa[find(it)]=find(it+1);
		for(auto it:v2[x-1]) fa[find(it+n+1)]=find(it+n+1+1);
		int cur=1,ans=0;
		while(cur<=n)
		{
			cur=min(find(cur),find(cur+n+1)-n-1);
			if(cur>n) break;
			++ans,cur+=x;
		}
		printf("%d%c",ans," \n"[x==n]);
	}
	return 0;
}