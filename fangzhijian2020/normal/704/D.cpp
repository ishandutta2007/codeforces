#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int INF=1e9;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x,y,opt,ans,l,D,R,B,tot,vis[200005],rd[200005],p[200005];map<int,int>mpx,mpy;
int id[100005],h[200010],cur[200010],cnt=1,s,t,S,T,sum[200010],d[200010];
struct edge{int to,next,v,opt;}e[5000005];
void add(int x,int y,int z,int opt){
	e[++cnt]=(edge){y,h[x],z,opt};h[x]=cnt;
	e[++cnt]=(edge){x,h[y],0,opt};h[y]=cnt;
}
void ADD(int x,int y,int l,int r){
	add(x,y,r-l,1);sum[x]-=l;sum[y]+=l;
}
int type;queue<int>q;
bool bfs(int s,int t,int opt){
	int i,y;while(!q.empty())q.pop();
	for(i=0;i<=T;++i)d[i]=0;d[s]=1;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(x==t)return 1;
		for(i=h[x];i;i=e[i].next){
			y=e[i].to;
			if(e[i].v&&e[i].opt|opt&&!d[y]){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return 0;
}
int dfs(int x,int maxf,int t,int opt){
	int y,ret=0;if(x==t)return maxf;
	for(int &i=cur[x];i;i=e[i].next){
		y=e[i].to;
		if(e[i].v&&e[i].opt|opt&&d[y]==d[x]+1){
			int del=dfs(y,min(e[i].v,maxf),t,opt);
			e[i].v-=del;e[i^1].v+=del;
			ret+=del;maxf-=del;
			if(!maxf)return ret;
		}
	}
	return ret;
}
int main(){
	n=read();m=read();R=read();B=read();
	if(R>B){swap(R,B);type=1;}
	for(int i=1;i<=n;++i){
		x=read();y=read();
		if(!mpx[x]){mpx[x]=++tot;vis[tot]=0;}
		if(!mpy[y]){mpy[y]=++tot;vis[tot]=1;}
		++rd[mpx[x]];++rd[mpy[y]];
		ADD(mpx[x],mpy[y],0,1);id[i]=cnt;
		
	}
	for(int i=1;i<=tot;++i)p[i]=rd[i];
	for(int i=1;i<=m;++i){
		opt=read();l=read();D=read();
		if(opt==1)p[mpx[l]]=min(p[mpx[l]],D);
		else p[mpy[l]]=min(p[mpy[l]],D);
	}
	s=tot+1;t=s+1;S=t+1;T=S+1;
	for(int i=1;i<=tot;++i){
		if((rd[i]-p[i]+1)/2>(rd[i]+p[i])/2){puts("-1");return 0;}
		if(!vis[i])ADD(s,i,(rd[i]-p[i]+1)/2,(rd[i]+p[i])/2);
		else ADD(i,t,(rd[i]-p[i]+1)/2,(rd[i]+p[i])/2);
	}
	int sums=0;
	for(int i=1;i<=tot+2;++i){
		if(sum[i]>0)add(S,i,sum[i],0),sums+=sum[i];
		if(sum[i]<0)add(i,T,-sum[i],0);
	}
	add(t,s,INF,0);
	while(bfs(S,T,1))memcpy(cur,h,sizeof(cur)),ans+=dfs(S,INF,T,1);
	if(ans!=sums){puts("-1");return 0;}
	ans=e[cnt].v;
	while(bfs(s,t,0))memcpy(cur,h,sizeof(cur)),ans+=dfs(s,INF,t,0);
	cout<<1ll*ans*R+1ll*(n-ans)*B<<"\n";
	for(int i=1;i<=n;++i)putchar(e[id[i]].v^type?'r':'b');
	return 0;
}