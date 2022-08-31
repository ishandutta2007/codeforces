#include<bits/stdc++.h>
#include<cstring>
#define re register
using namespace std;
struct Flow{
inline int min(re int x,re int y) {
	return x<y?x:y;
}
struct edge {
	int to,next,w,kk;
} e[510005];
int n,dis[503],gap[503],mxd,dlt,ans,cnt=1,head[503],m,s,t,a,b,c,d,v[503],dn[503],ss,tt;
queue<int>q;
inline void add(re int x,re int y,re int z,re int aa) {
	e[++cnt].to=y;
	e[cnt].w=z;
	e[cnt].next=head[x];
	e[cnt].kk=aa;
	head[x]=cnt;
	e[++cnt].to=x;
	e[cnt].w=0;
	e[cnt].next=head[y];
	head[y]=cnt;
	e[cnt].kk=aa;
}
inline void add(re int x,re int y,re int z1,re int z2,re int id){
	add(x,y,z2-z1,id);
	dn[y]+=z1;
	dn[x]-=z1;
}
inline int dfs(re int x,re int y) {
	if(x==t)return y;
	int tmp=0;
	for(re int i=head[x]; i; i=e[i].next) {
		int z=e[i].to;
		if(e[i].w&&dis[x]==dis[z]+1) {
			dlt=dfs(z,min(y,e[i].w));
			tmp+=dlt;
			e[i].w-=dlt;
			e[i^1].w+=dlt;
			if(dis[s]==n||(y-=dlt)==0)return tmp;
		}
	}
	if(!(--gap[dis[x]]))dis[s]=n;
	++gap[++dis[x]];
	return tmp;
}
void solve(re int sss,re int ttt) {
	int sum=0;
	ss=sss;
	tt=ttt;
	s=n+1;
	t=s+1;
	for(re int i=1; i<=n; ++i) {
		if(dn[i]>0)add(s,i,dn[i],0),sum+=dn[i];
		else if(dn[i]<0)add(i,t,-dn[i],0);
	}
	add(tt,ss,1<<29,0);
	n+=2;
	q.push(t);
	v[t]=1;
	while(!q.empty()) {
		re int tmp=q.front();
		q.pop();
		for(re int i=head[tmp]; i; i=e[i].next) {
			if(!v[e[i].to]) {
				v[e[i].to]=1;
				++gap[dis[e[i].to]=dis[tmp]+1];
				q.push(e[i].to);
			}
		}
	}
	while(dis[s]<n)dfs(s,1<<30);
	ans=(1<<29)-e[cnt-1].w;
	for(re int i=2; i<=cnt; ++i)if(!e[i].kk)e[i].w=0;
	s=ss;
	t=tt;
	memset(gap,0,sizeof(gap));
	memset(v,0,sizeof(v));
	n-=2;
	q.push(t);
	v[t]=1;
	while(!q.empty()) {
		re int tmp=q.front();
		q.pop();
		for(re int i=head[tmp]; i; i=e[i].next) {
			if(!v[e[i].to]) {
				v[e[i].to]=1;
				++gap[dis[e[i].to]=dis[tmp]+1];
				q.push(e[i].to);
			}
		}
	}
	while(dis[s]<n)ans+=dfs(s,1<<30);
}
}GG;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline int min(re int x,re int y){return x<y?x:y;}
int gap[1000002],dis[1000002],n,head[1000002],cnt=1,S,T,q[1000002],hd,tl,m,v[1000002],X[1002],Y[1002],Z[1002];
char tg[1002];
struct edge{int to,next,w,id;}e[2000002],e1[2000002];
inline void add(re int x,re int y,re int z,re int id=0){e[++cnt]=(edge){y,head[x],z,id},head[x]=cnt;e[++cnt]=(edge){x,head[y],0,id},head[y]=cnt;}
inline void clr(){
	cnt=1;
	for(re int i=1;i<=n;++i)head[i]=0;
	for(re int i=1;i<=m;++i)if(!tg[i]){
		add(X[i],Y[i],Z[i]?1:100000000);
		if(Z[i])add(Y[i],X[i],100000000);
	}
} 
inline int dfs(re int x,re int y){
	if(x==T)return y;
	re int tmp=0;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].w&&dis[x]==dis[e[i].to]+1){
			re int dlt=dfs(e[i].to,min(y,e[i].w));
			y-=dlt,e[i].w-=dlt,e[i^1].w+=dlt,tmp+=dlt;
			if(!y||dis[S]==n)return tmp;
		}
	if(!(--gap[dis[x]]))dis[S]=n;
	++gap[++dis[x]];
	return tmp;
}
inline int SAP(){
	for(re int i=1;i<=n;++i)v[i]=0,dis[i]=gap[i]=0;
	dis[q[hd=tl=1]=T]=0,v[T]=1;;
	while(hd<=tl){
		re int x=q[hd++];
		for(re int i=head[x];i;i=e[i].next)if(!v[e[i].to])v[e[i].to]=1,++gap[dis[e[i].to]=dis[x]+1],q[++tl]=e[i].to;
	}
	re int ans=0;
	while(dis[S]<n)ans+=dfs(S,1e9);
	return ans;
}
int main(){
	n=read(),m=read(),S=read(),T=read();
	for(re int i=1,x,y,z;i<=m;++i)X[i]=read(),Y[i]=read(),Z[i]=read();
	clr();re int lst=SAP();
	printf("%d\n",lst);
	for(re int i=1;i<=m;++i)if(Z[i]){
		tg[i]=1;clr();
		re int cc=SAP();
		if(cc==lst-1)lst=cc;
		else tg[i]=0;
	}
	memset(head,0,sizeof(head)),cnt=1;GG.n=n;
	for(re int i=1;i<=m;++i)if(Z[i]&&!tg[i])GG.add(X[i],Y[i],1,1000000000,i);else if(Z[i])GG.add(X[i],Y[i],1,1,i);
	GG.solve(S,T);
	for(re int i=1;i<=m;++i){
		re int s=0;
		for(re int j=GG.head[X[i]];j;j=GG.e[j].next)if(GG.e[j].kk==i)s=GG.e[j^1].w;
		if(Z[i]){++s;
			if(tg[i])printf("%d %d\n",s,1);
			else printf("%d %d\n",s,1000000000);
		}
		else printf("%d %d\n",0,1);
	}
	
}