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

const int N=2005;
std::bitset<N> A[N],s[N];
bool mark[N],used[N];
int cnt[N][N],pos;
pi valid[N*N];
void MAIN()
{
	memset(mark,0,sizeof(mark));
	memset(used,0,sizeof(used));
	int n,m;read(n,m);
	for(int i=0;i<=n+1;++i) for(int j=0;j<=n+1;++j) cnt[i][j]=0;
	for(int i=1;i<=n;++i) A[i].reset();
	for(int i=1;i<=m;++i)
	{
		s[i].reset();
		for(int j=1;j<=n;++j)
		{
			char ch(getchar());while(ch!='0'&&ch!='1') ch=getchar();
			if(ch=='1') s[i].set(j),A[j].set(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		int tmp=A[i].count();
		for(int j=1;j<=n;++j) cnt[i][j]=tmp-(A[i]&A[j]).count();
		cnt[i][i]=inf;
	}
	pos=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(!cnt[i][j]) valid[++pos]=mkpr(i,j);
	std::vector<pi> ans;
	while(SZ(ans)<n-1)
	{
		for(int j=1;j<=m;++j)
		{
			if(!mark[j]&&s[j].count()<=1)
			{
				mark[j]=true;
				int tmp=s[j]._Find_first();
				if(tmp<N)
				{
					for(int k=1;k<=n;++k) if(k!=tmp) if(!--cnt[tmp][k]) valid[++pos]=mkpr(tmp,k);
					A[tmp].reset(j);
				}
			}
		}
		bool flag=false;
		while(pos)
		{
			pi tmp=valid[pos--];
			if(used[tmp.first]||used[tmp.second]) continue;
			used[tmp.first]=flag=true;
			ans.pb(tmp);
			for(int t=1;t<=m;++t) s[t].reset(tmp.first);
		}
		if(!flag) break;
	}
	if(SZ(ans)<n-1) puts("NO");
	else
	{
		printf("YES\n");
		for(auto it:ans) printf("%d %d\n",it.first,it.second);
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}