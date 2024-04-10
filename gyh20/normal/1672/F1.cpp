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
int t,n,m,a[1000002],ans,A,B,p1,p2,b[1000002],c[1000002],p[1000002];
char s[1000002];
vector<int>G[200002];
inline bool cmp(re int x,re int y){return a[x]<a[y];}
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),c[i]=0,G[i].clear(),assert(a[i]<=n);
		for(re int i=1;i<=n;++i)G[++c[a[i]]].push_back(i);
		for(re int i=1;i<=n;++i)if(G[i].size()){
			sort(G[i].begin(),G[i].end(),cmp);
			for(re int j=0;j+1<G[i].size();++j)p[G[i][j]]=G[i][j+1];
			p[G[i][G[i].size()-1]]=G[i][0];
		}
		for(re int j=1;j<=n;++j)printf("%d ",a[p[j]]);puts("");
	}
}