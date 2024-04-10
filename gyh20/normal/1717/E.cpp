#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
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
int t,n,m,a[1000002],ans,A,B,C,f[100002],g[100002];
char s[1000002];
vector<int>D[100002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)for(re int j=i;j<=n;j+=i)D[j].push_back(i);
	for(re int i=1;i<=n;++i){
		for(re int j=0;j<D[i].size();++j){
			re int x=D[i][j];
			f[x]=i/x-1;
		}
		for(re int j=D[i].size()-1;~j;--j){
			re int x=D[i][j];
			for(auto o:D[x])if(o^x)add(f[o],M-f[x]);
		}
		for(re int j=0;j<D[i].size();++j){
			re int x=D[i][j];
			add(g[i],1ll*x*f[x]%M);
		}
	}
	for(re int i=1;i<n;++i){
		for(re int j=0;j<D[i].size();++j){
			re int x=D[i][j];
			if((n-i)%x==0)f[x]=1ll*x*g[(n-i)/x]%M;
			else f[x]=0;
		}
		for(re int j=D[i].size()-1;~j;--j){
			re int x=D[i][j];
			for(auto o:D[x])if(o^x)add(f[o],M-f[x]);
		}
		for(re int j=0;j<D[i].size();++j){
			re int x=D[i][j];
			add(ans,1ll*i/x*f[x]%M);
		}
	}printf("%d",ans);
}