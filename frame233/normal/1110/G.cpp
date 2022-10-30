// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=500005;
std::vector<int> e[N];
char s[N];
int st[N],n;
bool check()
{
	for(int i=1;i<=n;++i)if(st[i]==1)
	{
		int cnt=0;
		for(auto v:e[i]) cnt+=st[v]==1;
		if(cnt>=2) return true;
	}
	return false;
}
bool dfs2();
bool dfs1()
{
	int cnt=0;
	for(int i=1;i<=n;++i) cnt+=st[i]==0;
	if(!cnt) return check();
	for(int i=1;i<=n;++i)if(!st[i])
	{
		st[i]=1;
		if(dfs2()) return st[i]=0,true;
		st[i]=0;
	}
	return false;
}
bool dfs2()
{
	int cnt=0;
	for(int i=1;i<=n;++i) cnt+=st[i]==0;
	if(!cnt) return check();
	for(int i=1;i<=n;++i)if(!st[i])
	{
		st[i]=-1;
		if(!dfs1()) return st[i]=0,false;
		st[i]=0;
	}
	return true;
}
void MAIN()
{
	read(n);
	for(int i=1;i<=n;++i) e[i].clear();
	memset(st,0,(n+3)<<2);
	int x,y;
	for(int i=1;i<n;++i) read(x,y),e[x].pb(y),e[y].pb(x);
	read_str(s+1);
	for(int i=1;i<=n;++i)if(SZ(e[i])>3){puts("White");return;}
	for(int i=1;i<=n;++i)if(SZ(e[i])==3)
	{
		int cnt=0;
		for(auto v:e[i]) for(auto it:e[v])if(it!=i){++cnt;break;}
		if(cnt>=2){puts("White");return;}
	}
	if(n<=9)
	{
		for(int i=1;i<=n;++i) if(s[i]=='W') st[i]=1;
		if(dfs1()) puts("White");
		else puts("Draw");
	}
	else
	{
		for(int i=1;i<=n;++i)if(s[i]=='W')
		{
			if(SZ(e[i])>1){puts("White");return;}
			if(SZ(e[e[i][0]])==3){puts("White");return;}
		}
		int cnt=0,qwq=0;
		for(int i=1;i<=n;++i) if(SZ(e[i])==2) ++cnt;else if(SZ(e[i])==3) ++qwq;
		if(qwq==2&&cnt%2) puts("White");
		else puts("Draw");
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}