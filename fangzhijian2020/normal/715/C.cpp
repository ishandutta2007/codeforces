#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=100000;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}

int n,m,mi[N+5],inv[N+5],x,y,z,h[N+5],cnt;long long ans;
int exgcd(int a,int b,int&x,int&y){
	if(b==0){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	x=x-(a/b)*y;swap(x,y);return d;
}
int Inv(){
	int x,y,d;
	d=exgcd(10,m,x,y);
	return (x%m+m)%m;
}
struct edge{int to,next,v;}e[(N<<1)+5];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
}
int core,Min,vis[N+5],size[N+5],s1[N+5],s2[N+5],dis[N+5];
void findcore(int x,int prt,int N){
	int i,y,Max=0;size[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt||vis[y])continue;
		findcore(y,x,N);size[x]+=size[y];
		Max=max(Max,size[y]);
	}
	Max=max(Max,N-size[x]);
	if(Max<Min){Min=Max;core=x;}
}
int Next;map<int,int>A,a,B,b;
void solve(int x,int opt){
	if(opt!=Next){Next=opt;a.clear();b.clear();}
	int t1=1ll*s1[x]*inv[dis[x]]%m,t2=s2[x];
	ans+=A[(m-t2)%m]+B[(m-t1)%m];++A[t1];++B[t2];
	ans-=a[(m-t2)%m]+b[(m-t1)%m];++a[t1];++b[t2];
}
void dfs(int x,int prt,int opt){
	int i,y;if(opt)solve(x,opt);size[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt||vis[y])continue;
		s1[y]=(10ll*s1[x]+e[i].v)%m;
		s2[y]=(s2[x]+1ll*mi[dis[x]]*e[i].v)%m;
		dis[y]=dis[x]+1;dfs(y,x,opt?opt:y);
		size[x]+=size[y];
	}
}
void DFS(int x){
	int i,y;s1[x]=s2[x]=dis[x]=0;vis[x]=1;
	dfs(x,0,0);ans+=A[0]+B[0];
	A.clear();B.clear();Next=0;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(vis[y])continue;
		Min=n;findcore(y,x,size[y]);DFS(core);
	}
}
int main(){
	n=read();m=read();
	int tmp=Inv();
	mi[0]=inv[0]=1;
	for(int i=1;i<=n;++i){
		mi[i]=10ll*mi[i-1]%m;
		inv[i]=1ll*inv[i-1]*tmp%m;
	}
	if(m==1){printf("%lld\n",1ll*n*(n-1));return 0;}
	for(int i=1;i<n;++i){
		x=read()+1;y=read()+1;z=read();
		add(x,y,z);add(y,x,z);
	}
	Min=n;findcore(1,0,n);DFS(core);
	printf("%lld\n",ans);
	return 0;
}