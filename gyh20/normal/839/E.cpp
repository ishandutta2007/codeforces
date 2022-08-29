#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,f[1048576],m,lmt,ans;
double K;
bitset<41>B[42];
inline void dfs(re int x,re int y,bitset<41>cur){
	if(x==lmt){
		f[y]=__builtin_popcount(y);
		return;
	}
	dfs(x+1,y,cur);
	if((B[x]&cur)==cur)cur[x]=1,dfs(x+1,y|(1<<x),cur);
}
inline void dfs1(re int x,re int y,bitset<41>cur,bitset<41>T){
	if(x==n){
		re int zt=0;
		for(re int i=0;i<lmt;++i)if(T[i])zt|=(1<<i);
		ans=max(ans,y+f[zt]);
		return;
	}
	dfs1(x+1,y,cur,T);
	if((B[x]&cur)==cur)cur[x]=1,dfs1(x+1,y+1,cur,T&B[x]);
}
int main(){
	n=read(),lmt=n>>1,K=read();
	for(re int i=0;i<n;++i)for(re int j=0;j<n;++j)B[i][j]=read();
	bitset<41>tmp,fl;
	for(re int i=0;i<n;++i)fl[i]=1;
	dfs(0,0,tmp);
	for(re int i=0;i<(1<<lmt);++i)
		if(f[i]){
			for(re int j=0;j<lmt;++j)f[i|(1<<j)]=max(f[i|(1<<j)],f[i]);
		}
	dfs1(lmt,0,tmp,fl);
	re double val=K/ans;
	printf("%.10lf",val*val*ans*(ans-1)/2.0);
}