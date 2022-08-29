#include<bits/stdc++.h>
#define re register
using namespace std;
int a[40],p[300002],q[300002],k,t,n,m,b;
inline int max(int x,int y){return x>y? x:y;}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
void dfs1(int i,int sum){
	if(i==b){p[++k]=sum,p[++k]=(sum+a[b])%m;return;}
	dfs1(i+1,sum),dfs1(i+1,(sum+a[i])%m);
}
void dfs2(int i,int sum){
	if(i==n){q[++t]=sum,q[++t]=(sum+a[n])%m;return;}
	dfs2(i+1,sum),dfs2(i+1,(sum+a[i])%m);
}
int main(){
	re int i,j,ans=0;
	n=read(),m=read(),b=n>>1;
	for(i=1;i<=n;++i) a[i]=read();
	if(n==1)return printf("%d",a[1]%m),0;
	dfs1(1,0),dfs2(b+1,0),i=0,j=t;
	sort(p+1,p+k+1),sort(q+1,q+t+1);
	while(i<=k){
		while(p[i]+q[j]>=m)--j;
		ans=max(ans,p[i]+q[j]),++i;
	}
	ans=max(ans,p[k]+q[t]-m);
	printf("%d",ans);
}