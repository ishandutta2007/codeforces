#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<iostream>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
inline int max(re int x,re int y){
	return x>y?x:y;
}
inline int min(re int x,re int y){
	return x<y?x:y;
}
map<int,int>pos;
set<int>s;
set<int> :: iterator it;
int t,a[500002],dp[500002],dp1[500002],n,lst[500005],p,mx,ans[500005];
signed main(){
n=read();
for(re int i=1;i<=n;++i)a[i]=read();
for(re int i=1;i<=n;++i){
	lst[i]=0;
	for(re int j=i-1;j>=1;--j){
		if(a[i]>=a[j]){
			lst[i]=j;
			break;
		}
	}
}
for(re int i=1;i<=n;++i){
	dp[i]=dp[lst[i]]+(i-lst[i])*a[i];
}
reverse(a+1,a+n+1);
for(re int i=1;i<=n;++i){
	lst[i]=0;
	for(re int j=i-1;j>=1;--j){
		if(a[i]>=a[j]){
			lst[i]=j;
			break;
		}
	}
}
for(re int i=1;i<=n;++i){
	dp1[i]=dp1[lst[i]]+(i-lst[i])*a[i];
}
reverse(dp1+1,dp1+n+1);
for(re int i=1;i<=n;++i){
	if(dp[i]+dp1[i+1]>mx){
		mx=dp[i]+dp1[i+1];
		p=i;
	}
}
reverse(a+1,a+n+1);
mx=a[p];
for(re int i=p;i>=1;--i){	
mx=min(mx,a[i]);
	ans[i]=mx;

}
mx=a[p+1];
for(re int i=p+1;i<=n;++i){	
mx=min(mx,a[i]);
	ans[i]=mx;

}
for(re int i=1;i<=n;++i)printf("%lld ",ans[i]);
}