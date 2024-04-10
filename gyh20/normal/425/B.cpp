#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,k,t,dp[102][2],ans,f[12][1024],sss;
bitset<102>a[102],tmp;
inline void check(re int x,re int sum=0){
	for(re int i=1;i<=n;++i){
		if(i==x)continue;
		tmp=a[i]^a[x];
		sum+=min(tmp.count(),m-tmp.count());
		if(sum>k)return;
	}
	ans=min(ans,sum);
}
inline void dfs(re int x,re int y){
	if(x==m)return check(1,y);
	dfs(x+1,y),a[1][x].flip(),dfs(x+1,y+1),a[1][x].flip();
}
int main(){
	t=1;
	while(t--){
		n=read(),m=read(),k=read(),ans=1e9;
		if(n>m&&min(n,m)<=k)
		for(re int i=1;i<=n;++i){
			a[i].reset();
			for(re int j=0;j<m;++j)a[i][j]=read();
		}
		else{
			swap(n,m);
			for(re int i=1;i<=n;++i)
			a[i].reset();
			for(re int j=0;j<m;++j)
		for(re int i=1;i<=n;++i){a[i][j]=read();
		}
		}
		if(k<n){
			for(re int i=1;i<=k+1;++i)check(i);
			printf("%d\n",(ans>k)?-1:ans);
		}
		else{
			dfs(0,0);
			printf("%d\n",(ans>k)?-1:ans);
		}
	}
}