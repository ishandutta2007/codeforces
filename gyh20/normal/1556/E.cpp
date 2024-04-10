#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[100002],s[100002],mx[22][100002],mn[22][100002],L[100002];
inline int ask1(re int l,re int r){
	re int tmp=L[r-l+1];
	return max(mx[tmp][l],mx[tmp][r-(1<<tmp)+1]);
}
inline int ask2(re int l,re int r){
	re int tmp=L[r-l+1];
	return min(mn[tmp][l],mn[tmp][r-(1<<tmp)+1]);
}
signed main(){
	n=read(),m=read();
	for(re int i=2;i<=n;++i)L[i]=L[i>>1]+1;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)a[i]-=read(),s[i]=s[i-1]+a[i],mx[0][i]=mn[0][i]=s[i];
	for(re int i=1;i<=20;++i)
		for(re int j=1;j+(1<<i)-1<=n;++j)
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]),mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
	while(m--){
		re int l=read(),r=read(),X=ask1(l,r),Y=ask2(l,r);
		if(s[r]-s[l-1]!=0)puts("-1");
		else if(X>s[l-1])puts("-1");
		else printf("%lld\n",s[l-1]-Y);
	}
}