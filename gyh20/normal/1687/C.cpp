#include<bits/stdc++.h>
#define re register
#define int long long
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
int t,n,m,a[1000002],ans,A,B,b[1000002],sum[1000002],pos,fa[1000002];
char s[1000002];
vector<int>R[1000002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void chk(re int x){
	vector<int>tmp;
	for(auto z:R[x]){
		re int l=z,r=x;
		if(l>r)swap(l,r);
		if(sum[l]||sum[r])continue;
		for(re int i=root(l);i<=r;i=root(i))tmp.push_back(i),sum[i]=0,fa[i]=i+1;
	}
	for(auto z:tmp)chk(z);
}
signed main(){
	t=read();
	while(t--){
		n=read(),pos=0,m=read();
		for(re int i=1;i<=n;++i)a[i]=read(),R[i].clear(),fa[i]=i;fa[0]=0,fa[n+1]=n+1;R[0].clear();
		for(re int i=1;i<=n;++i)a[i]-=read();
		for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		while(m--){
			re int x=read()-1,y=read();
			R[x].push_back(y),R[y].push_back(x);
		}
		for(re int i=0;i<=n;++i)if(!sum[i])fa[i]=i+1;
		for(re int i=0;i<=n;++i)if(!sum[i])chk(i);
		re bool ia=1;
		for(re int i=0;i<=n;++i)ia&=fa[i]!=i;
		puts(ia?"YES":"NO");
	}
}