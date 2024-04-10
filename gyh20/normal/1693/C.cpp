#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
vector<int>G[1000002],H[1000002];
int t,n,m,a[1000002],ans,A,B,dis[1000002],Q[1000002],hd,tl,p[1000002],tot,f[1000002],deg[1000002];
char s[1000002],v[1000002];
inline bool cmp(re int x,re int y){return f[x]<f[y];}
struct node{
	int x,y;
	bool operator <(const node A)const{return y>A.y;}
}h[200002];
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();++deg[x];
		G[x].push_back(y);
		H[y].push_back(x);
	}
	Q[hd=tl=1]=1,v[1]=1;
	while(hd<=tl){
		re int x=Q[hd++];p[++tot]=x;
		for(auto z:G[x])if(!v[z])v[z]=1,dis[z]=dis[x]+1,Q[++tl]=z;
	}
	for(re int i=1;i<=n;++i)h[i].x=i,h[i].y=1e9;
	h[n].y=0;priority_queue<node>Q;
	Q.push(h[n]);
	while(!Q.empty()){
		re node x=Q.top();Q.pop();
		if(x.y!=h[x.x].y)continue;
		for(auto z:H[x.x]){
			--deg[z];
			if(deg[z]+x.y+1<h[z].y)h[z].y=deg[z]+x.y+1,Q.push(h[z]);
		}
	}
	printf("%d",h[1].y);
}