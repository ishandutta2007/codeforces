#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,q,cnt,head[100002],A[100002],B[100002],C[100002],tim,v[100002],ds[100002];
vector<int>G[100002];
ll inf=1e18,D[100002],F[100002];
struct edge{int to,next,w;}e[100002];
struct node{
	int pos;ll dis;
	bool operator <(const node A)const{return dis>A.dis;}
}h[100002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void Dis(){
	priority_queue<node>Q;
	for(re int i=1;i<=n;++i)h[i]=(node){i,inf};h[1].dis=0;Q.push(h[1]);
	while(!Q.empty()){
		re node x=Q.top();Q.pop();
		if(x.dis!=h[x.pos].dis)continue;
		for(re int i=head[x.pos];i;i=e[i].next)
			if(x.dis+e[i].w<h[e[i].to].dis)
				h[e[i].to].dis=x.dis+e[i].w,Q.push(h[e[i].to]);
	}
	for(re int i=1;i<=n;++i)D[i]=F[i]=h[i].dis;
} 
int main(){
	n=read(),m=read(),q=read();
	for(re int i=1;i<=m;++i)A[i]=read(),B[i]=read(),C[i]=read(),add(A[i],B[i],C[i]);Dis();
	for(re int ii=1;ii<=q;++ii){
		re int o=read(),k=read();
		if(o==1)printf("%lld\n",F[k]==inf?-1:D[k]);
		else{
			++tim;int kk=min(k,n);
			while(k--)++C[read()];
			memset(head,0,sizeof(head)),cnt=0;
			for(re int i=1;i<=m;++i)if(ds[B[i]]!=inf&&ds[A[i]]!=inf)add(A[i],B[i],C[i]-(D[B[i]]-D[A[i]]));
			memset(ds,0x3f,sizeof(ds)),ds[1]=0,G[0].push_back(1);
			for(re int i=0;i<=n;++i)
				while(G[i].size()){
					re int x=G[i].back();G[i].pop_back();if(ds[x]^i)continue;
					for(re int j=head[x];j;j=e[j].next)if(ds[x]+e[j].w<ds[e[j].to]&&ds[x]+e[j].w<=kk)ds[e[j].to]=ds[x]+e[j].w,G[ds[e[j].to]].push_back(e[j].to);
				}
			for(re int i=1;i<=n;++i)D[i]+=ds[i];
		}
	}
}