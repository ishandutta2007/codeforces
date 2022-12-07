#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 2000005
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
const int mod=51123987;
int n,ans,f[N];
char s[N];
namespace pam
{
	int siz,last,fail[N],num[N],len[N];
	int cnt,head[N],nxt[N],to[N],w[N];
	void add(int u,int v,int c)
	{
		nxt[++cnt]=head[u];head[u]=cnt;to[cnt]=v;w[cnt]=c;
	}
	void init()
	{
		cnt=0;
		memset(head,0,sizeof head);
		s[0]=66;
		siz=last=2;
		len[1]=-1;
		len[2]=0;
		fail[2]=1;
		memset(nxt,0,sizeof nxt);
	}
	int insert(int x)
	{
//		cerr<<x<<" "<<last<<" "<<len[last]<<endl;
//		cerr<<len[fail[last]]<<endl;
		while(s[x] != s[x-len[last]-1])last=fail[last];
		int go=0;
		for(int i=head[last];i;i=nxt[i])
			if(w[i]==s[x])
				go=to[i];
		if(!go)
		{
			go=++siz;
			add(last,go,s[x]);
			len[siz]=len[last]+2;
			int k=fail[last];
			while(k && s[x]!=s[x-len[k]-1])k=fail[k];
			if(k)
			{
				for(int i=head[k];i;i=nxt[i])
					if(w[i]==s[x])
						fail[siz]=to[i];
			}
			else fail[siz]=2;
			num[siz]=num[fail[siz]]+1;
		}
		last=go;
		return num[last];
	}
}
int main()
{
	re(n);
	scanf("%s",s+1);
	using namespace pam;
	init();
	for(int i=1;i<=n;++i)
		s[i]-='a',f[i]=(f[i-1]+insert(i))%mod;
//	for(int i=1;i<=n;++i)
//		printf("%d ",f[i]); 
	ans=f[n]*(f[n]-1ll)/2%mod;
	reverse(s+1,s+n+1);
	init();
	for(int i=1;i<n;++i)
		ans=(ans-1ll*insert(i)*f[n-i])%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}