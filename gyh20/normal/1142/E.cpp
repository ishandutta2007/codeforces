#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,Q[100002],hd,tl,d[100002],rt,num;
char v[100002],ist[100002];
vector<int>A[100002],G[100002];
inline void dfs(re int x){
	ist[x]=v[x]=1;
	for(auto z:A[x])
		if(!ist[z]){
			G[x].push_back(z),++d[z];
			if(!v[z])dfs(z);
		}ist[x]=0;
}
inline int ask(re int x,re int y){assert(++num<=n);
	printf("? %d %d\n",x,y),fflush(stdout);
	return read();
}
int main(){
	n=read(),m=read(),hd=1;
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),A[x].push_back(y);
	for(re int i=1;i<=n;++i)if(!v[i])dfs(i);
	for(re int i=1;i<=n;++i)if(!d[i])Q[++tl]=i;
	rt=Q[hd++];
	while(hd<=tl){
		re int x=Q[hd++];
		if(ask(x,rt))swap(x,rt);
		for(auto z:G[x])if(!--d[z])Q[++tl]=z;
	}printf("! %d",rt),fflush(stdout);
}