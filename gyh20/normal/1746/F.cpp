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
long long c[42][300002];
int a[300002],n,q,tot;
inline void add(long long*C,int x,int y){for(;x<=n;x+=x&(-x))C[x]+=y;}
inline long long ask(long long*C,int x,long long s=0){for(;x;x^=x&(-x))s+=C[x];return s;}
unsigned int V[42][600002];
map<int,int>vis;
mt19937 rng(18912);
inline void Add(re int x,re int y,re int z){
	if(!vis.count(y))vis[y]=++tot;
	y=vis[y];
	for(re int i=1;i<=40;++i){
		while(V[i][y]==0)V[i][y]=rng();
		add(c[i],x,V[i][y]*z);
	}
}
int main(){
	n=read(),q=read();
	for(re int i=1;i<=n;++i)Add(i,a[i]=read(),1);
	while(q--){
		int o=read(),l=read(),r=read();
		if(o==1)Add(l,a[l],-1),Add(l,a[l]=r,1);
		else{
			re bool ia=1;int k=read();
			for(re int i=1;i<=40;++i)ia&=(ask(c[i],r)-ask(c[i],l-1))%k==0;
			puts(ia?"YES":"NO");
		}
	}
}