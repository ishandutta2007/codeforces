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

const int N=10000005;
int ch[N][2],fail[N],l[N],b[N],node_cnt,id[N],iid[N],last[N];
char s[N];
void insert(char *s,int len,int ID)
{
	int cur=0;
	for(int i=0;i<len;++i)
	{
		int tmp=s[i]-'a';
		if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
		cur=ch[cur][tmp];
	}
	id[cur]=ID;
}
int _q[N],_l,_r;
void build()
{
	_l=1,_r=0;
	for(int i=0;i<2;++i) if(ch[0][i]) _q[++_r]=ch[0][i];
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		if(!id[x]) id[x]=id[fail[x]];
		last[x]=id[fail[x]];
		for(int i=0;i<2;++i)
		{
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],_q[++_r]=ch[x][i];
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
bool a[755][755];
int vis[755],mat[755],to[755],tim,n;
bool dfs(int x)
{
	for(int v=1;v<=n;++v)
	{
		if(!a[x][v]||vis[v]==tim) continue;
		vis[v]=tim;
		if(!mat[v]||dfs(mat[v]))
		{
			mat[v]=x,to[x]=v;
			return true;
		}
	}
	return false;
}
bool tag[1505];
void dfs2(int x)
{
	if(tag[x])return;
	tag[x]=true;
	for(int v=1;v<=n;++v)if(a[x][v]&&v!=to[x])
	{
		tag[v+n]=true;
		dfs2(mat[v]);
	}
}
int main()
{
	read(n);
	int cur=0;
	for(int i=1;i<=n;++i)
	{
		b[i]=cur;
		l[i]=read_str(s+cur);
		insert(s+cur,l[i],i);
		cur+=l[i];
	}
	build();
	for(int i=1;i<=n;++i)
	{
		int cur=0;
		for(int j=0;j<l[i];++j)
		{
			int tmp=s[b[i]+j]-'a';
			cur=ch[cur][tmp];
			if(id[cur]) a[i][id[cur]]=true;
			if(last[cur]) a[i][last[cur]]=true;
		}
	}
	for(int i=1;i<=n;++i) a[i][i]=0;
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]|=a[i][k]&&a[k][j];
	int ans=0;
	for(int i=1;i<=n;++i) ++tim,ans+=dfs(i);
	printf("%d\n",n-ans);
	for(int i=1;i<=n;++i) if(!to[i]) dfs2(i);
	for(int i=1;i<=n;++i) if(tag[i]&&!tag[i+n]) printf("%d ",i);
	printf("\n");
	return 0;
}