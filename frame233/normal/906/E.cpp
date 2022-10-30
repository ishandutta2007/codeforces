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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1000005;
char a[N],b[N],s[N];
int dp[N],pre[N];
pi f[N];
int last,node_cnt;
int fail[N],len[N],dif[N],slink[N];
int ch[N][26];
int calc(int x,int n)
{
	while(s[n]!=s[n-len[x]-1]) x=fail[x];
	return x;
}
void insert(int x)
{
	int nd=calc(last,x),c=s[x]-97;
	if(!ch[nd][c])
	{
		int cur=++node_cnt;
		len[cur]=len[nd]+2;
		fail[cur]=ch[calc(fail[nd],x)][c];
		dif[cur]=len[cur]-len[fail[cur]];
		slink[cur]=dif[cur]==dif[fail[cur]]?slink[fail[cur]]:fail[cur];
		ch[nd][c]=cur;
	}
	last=ch[nd][c];
}
int main()
{
	last=node_cnt=1;
	fail[0]=1,len[0]=0,fail[1]=1,len[1]=-1;
	int n=read_str(a+1);
	read_str(b+1);
	int m=0;
	for(int i=1;i<=n;++i) s[++m]=a[i],s[++m]=b[i];
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=m;++i)
	{
		insert(i);
		if(!(i&1)&&s[i]==s[i-1]) dp[i]=dp[i-2],pre[i]=i-2;
		for(int k=last;k>1;k=slink[k])
		{
			f[k]=mkpr(dp[i-len[slink[k]]-dif[k]],i-len[slink[k]]-dif[k]);
			if(slink[k]!=fail[k]&&f[fail[k]]<f[k]) f[k]=f[fail[k]];
			if(!(i&1)&&f[k].first+1<dp[i]) dp[i]=f[k].first+1,pre[i]=f[k].second;
		}
	}
	if(dp[m]>=inf) printf("-1\n");
	else
	{
		printf("%d\n",dp[m]);
		int cur=m;
		while(cur)
		{
			int tmp=pre[cur];
			if(tmp!=cur-2) printf("%d %d\n",(tmp>>1)+1,cur>>1);
			cur=tmp;
		}
	}
	return 0;
}