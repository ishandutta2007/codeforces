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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
inline bool check(re int x){
	for(re int i=1;i<=n;++i)b[i]=(a[i]>=x)?1:-1;
	re int mn=0,sum=-1e9;
	for(re int i=1;i<=n;++i){
		b[i]+=b[i-1];
		if(i>=m)mn=min(mn,b[i-m]),sum=max(sum,b[i]-mn);
	}
	return sum>0;
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	re int l=1,r=n;
	while(l<=r){
		re int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}