#include<algorithm>
#include<cstring>
#include<cstdio>
#define res register int
#define gc getchar
using namespace std;
const int mxn=110,inf=1e9;
int n,K,ln[mxn],siz[mxn],ans[mxn*mxn];
int t,h[mxn];
struct Tre
{
	int to,nxt;
}e[mxn];
inline int rd(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
void add(int u,int v) {e[++t]=(Tre){v,h[u]};h[u]=t;}
void dfs(int u)
{
	int v;siz[u]=ln[u]=1;
	for(int i=h[u];i;i=e[i].nxt) dfs(v=e[i].to),siz[u]+=siz[v],ln[u]=max(ln[u],ln[v]+1);
}
void getans(int u,int M)
{
	if(K==M) return ;
	ans[++*ans]=u;K--;
	for(int i=h[u];i&&K>M;i=e[i].nxt) getans(e[i].to,M),ans[++*ans]=u;
}
int main()
{
	for(int u,num,T=rd();T;--T)
	{
		memset(h+1,0,n<<2);t=0;
		n=rd();K=rd();ans[0]=0;
		for(int i=2;i<=n;++i) add(rd(),i);
		dfs(1);ans[0]=u=0;ans[++*ans]=1;
		for(int i=h[1];i;i=e[i].nxt)
			if(ln[e[i].to]>ln[u])
				u=e[i].to;
		K-=(num=min(K,ln[1]));
		for(int v,i=h[1];i&&K>siz[u]-ln[u];i=e[i].nxt)
			if((v=e[i].to)!=u)
				getans(v,siz[u]-ln[u]),ans[++*ans]=1;
		for(--num;num;--num)
		{
			ans[++*ans]=u;
			res v;
			for(int i=h[u];i;i=e[i].nxt)
				if(ln[e[i].to]+1==ln[u])
					{v=e[i].to;break;}
			for(int i=h[u];i&&K>siz[v]-ln[v];i=e[i].nxt)
				if(e[i].to!=v)
					getans(e[i].to,siz[v]-ln[v]),ans[++*ans]=u;
			u=v;
		}
		printf("%d\n",ans[0]-1);
		for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}