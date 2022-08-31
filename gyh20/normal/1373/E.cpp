#include<bits/stdc++.h>
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
using namespace std;
int t,n,m,a[1000002],x,b[1000002],k;
long long ans;
inline int count(re int x){
	re int sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
inline int calc(re int x){
	re int sum=0;
	for(re int i=x;i<x+k;++i)sum+=count(i);
	return sum; 
}
inline void dfs(re int x,re int y,re int z=0){
	if(y>ans||calc(y)>n)return;
	for(re int i=0;i<=9;++i)if(calc(y*10+i)==n)ans=min(ans,y*10+i);
	if(x==17)return;
	dfs(x+1,y*10+9,z);if(!z)dfs(x+1,y*10+8,1);
}
signed main(){
	t=read();
	while(t--){
		n=read();k=read()+1;
		ans=1e18;
		for(re int i=0;i<=10;++i)if(calc(i)==n)ans=min(ans,i);
		dfs(1,0);dfs(1,1);dfs(1,2);dfs(1,3);dfs(1,4);dfs(1,5);dfs(1,6);dfs(1,7);dfs(1,8);dfs(1,9);
		if(ans!=1e18)printf("%lld\n",ans);
		else puts("-1");
	}
}