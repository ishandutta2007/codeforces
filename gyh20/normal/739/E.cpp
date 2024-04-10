#include<bits/stdc++.h>
#define re register
#define eps 1e-10
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
double pa[2002],pb[2002],dp[2002],pos;
int n,na[2002],nb[2002],a,b;
inline void calc(re double x,re double y){
	for(re int i=1;i<=n;++i){
		dp[i]=dp[i-1],na[i]=na[i-1],nb[i]=nb[i-1];
		if(dp[i-1]+pa[i]-x-eps>dp[i])dp[i]=dp[i-1]+pa[i]-x,na[i]=na[i-1]+1,nb[i]=nb[i-1];
		if(dp[i-1]+pb[i]-y-eps>dp[i])dp[i]=dp[i-1]+pb[i]-y,na[i]=na[i-1],nb[i]=nb[i-1]+1;
		if(dp[i-1]+pa[i]-x+pb[i]-y-pa[i]*pb[i]-eps>dp[i])dp[i]=dp[i-1]+pa[i]-x+pb[i]-y-pa[i]*pb[i],na[i]=na[i-1]+1,nb[i]=nb[i-1]+1;
	}
}
inline double calc(re double x){
	re double l=0,r=1,mid;
	for(re int i=1;i<=50;++i){
		mid=(l+r)/2;
		calc(x,mid);
		if(nb[n]>b)l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	n=read(),a=read(),b=read();
	for(re int i=1;i<=n;++i)scanf("%lf",&pa[i]);
	for(re int i=1;i<=n;++i)scanf("%lf",&pb[i]);
	re double l=0,r=1,mid;
	for(re int i=1;i<=50;++i){
		mid=(l+r)/2;
		pos=calc(mid);
		if(na[n]>a)l=mid;
		else r=mid;
	}
	calc(l,pos);printf("%.5lf",dp[n]+l*a+pos*b);
}