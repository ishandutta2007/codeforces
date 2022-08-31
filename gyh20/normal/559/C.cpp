#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int l,r;
	bool operator<(const node &x)const{
		return l==x.l?r<x.r:l<x.l; 
	}
}p[800002];
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*x*ans%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
int fac[800002],inv[800002],dp1[800002];
inline int calc(re int n,re int m){
	return 1ll*fac[n+m-2]*inv[m-1]%M*inv[n-1]%M;
}
int dp[800002],n,m,ans,k;
signed main(){
	n=read(),m=read(),k=read();
	for(re int i=fac[0]=inv[0]=1;i<=n+m;++i)fac[i]=1ll*i*fac[i-1]%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=1;i<=k;++i)p[i].l=read(),p[i].r=read();
	ans=calc(n,m);
	sort(p+1,p+k+1);
	for(re int i=1;i<=k;++i){
		dp[i]=calc(p[i].l,p[i].r);
		for(re int j=1;j<i;++j)if(p[j].r<=p[i].r)add(dp[i],M-1ll*dp[j]*calc(p[i].r-p[j].r+1,p[i].l-p[j].l+1)%M);
	}
	for(re int i=1;i<=k;++i)add(ans,M-1ll*dp[i]*calc(n-p[i].l+1,m-p[i].r+1)%M);
	printf("%lld",ans);
}