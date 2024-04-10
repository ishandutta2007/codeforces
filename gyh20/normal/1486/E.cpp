#include<bits/stdc++.h>
#define re register
#define int unsigned int
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next,w;}e[30000002];
int t,n,m,a[1000002],ans,cnt,b[1000002],head[5500002],c[1000002];
inline void add(re int x,re int y,re int z){
	e[++cnt]=(edge){y,head[x],z};
	head[x]=cnt;
}
struct node{
	int pos,dis1;
	bool operator<(const node &x)const{
		return dis1>x.dis1;
	}
}h[5500002];
priority_queue<node>q;
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i){
		a[i]=read(),b[i]=read(),c[i]=read();
		add(a[i]+c[i]*n,b[i],0);
		add(b[i]+c[i]*n,a[i],0);
	}
	for(re int i=1;i<=m;++i){
		for(re int j=1;j<=50;++j)if(head[b[i]+j*n])add(a[i],b[i]+j*n,(j+c[i])*(j+c[i]));
		for(re int j=1;j<=50;++j)if(head[a[i]+j*n])add(b[i],a[i]+j*n,(j+c[i])*(j+c[i]));
	}
	for(re int i=1;i<=n*51;++i)h[i].pos=i,h[i].dis1=4e9;
	h[1].dis1=0;
	q.push((node){1,0});
	while(!q.empty()){
		node x=q.top();q.pop();
		if(x.dis1>h[x.pos].dis1)continue;
		for(re int i=head[x.pos];i;i=e[i].next)
			if(x.dis1+e[i].w<h[e[i].to].dis1){
				h[e[i].to].dis1=x.dis1+e[i].w;
				q.push(h[e[i].to]);
			}
	}
	for(re int i=1;i<=n;++i)if(h[i].dis1<4e9)printf("%u ",h[i].dis1);else printf("-1 ");
}