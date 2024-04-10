#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<queue>
#define re register
#define in inline
#define int long long
using namespace std;
const int Mxdt=50000;	 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int res=0;char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return res;
}
inline int min(re int x,re int y){
	return x<y?x:y;
}
struct edge{
	int fr,to,next,w;
}e[4000002];
int n,dis[500002],gap[500002],mxd,dlt,ans,cnt=1,head[500002],m,s,t,a,b,c,v[500002];
queue<int>q;
inline void add(re int x,re int y,re int z){
	e[++cnt].to=y;
	e[cnt].w=z;
	e[cnt].fr=x;
	e[cnt].next=head[x];
	head[x]=cnt;
	e[++cnt].to=x;
	e[cnt].w=0;
	e[cnt].fr=y;
	e[cnt].next=head[y];
	head[y]=cnt;
}
inline int dfs(re int x,re int y){
	if(x==t)return y;
	int tmp=0;
	for(re int i=head[x];i;i=e[i].next){
		int z=e[i].to;
		if(e[i].w&&dis[x]==dis[z]+1){
			dlt=dfs(z,min(y,e[i].w));
			tmp+=dlt;
			e[i].w-=dlt;
			e[i^1].w+=dlt;
			if(dis[s]==t||(y-=dlt)==0)return tmp;
		}
	}
	if(!(--gap[dis[x]]))dis[s]=t;
	++gap[++dis[x]];
	return tmp;
}
signed main(){
	n=read();
	m=read();
	s=m+n+1;
	t=s+1;
	for(re int i=1;i<=n;++i)add(i,t,read());
	int sum=0;
	for(re int i=1;i<=m;++i){
		a=read();
		b=read();
		sum+=(c=read());
		add(s,i+n,c);
		add(i+n,a,1ll<<60);
		add(i+n,b,1ll<<60);
	}
	q.push(t);
		v[t]=1;
		while(!q.empty()){
			re int tmp=q.front();
			q.pop();
			for(re int i=head[tmp];i;i=e[i].next){
				if(!v[e[i].to]){v[e[i].to]=1;
					++gap[dis[e[i].to]=dis[tmp]+1];
					q.push(e[i].to);
				}
			}
		}
	while(dis[s]<t)ans+=dfs(s,1ll<<60);
	printf("%lld",sum-ans);
}