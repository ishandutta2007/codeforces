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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
set<int>S[200002]; 
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read();
		if(x>y)swap(x,y);
		S[x].insert(y);
	}
	ans=n;
	for(re int i=1;i<=n;++i)if(S[i].size()&&*(--S[i].end())>i)--ans;
	re int q=read();
	while(q--){
		re int o=read();
		if(o==3)printf("%d\n",ans);
		else{
			re int x=read(),y=read();
			if(x>y)swap(x,y);
			if(S[x].size()&&*(--S[x].end())>x)++ans;
			if(o==1)S[x].insert(y);
			else S[x].erase(y);
			if(S[x].size()&&*(--S[x].end())>x)--ans;
		}
	}
}