#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int sqr(re int x){
	return x*x;
}
inline int calc(re int *a,re int* b,re int* c,re int ra,re int rb,re int rc){
	re int l=1,r=1,ans=6e18;a[ra+1]=1e18;
	for(re int i=1;i<=ra;++i){
		while(b[l]<a[i+1]&&l<=rb){
		if(l>rb)return ans;
		while(c[r]<b[l]&&r<=rc)++r;if(r>rc)return ans;
		ans=min(ans,sqr(a[i]-b[l])+sqr(a[i]-c[r])+sqr(b[l]-c[r]));++l;}
	}
	
	return ans;
}
int t,n,m,a[100002],b[100002],c[100002],ra,rb,rc;
signed main(){
	t=read();
	while(t--){
		ra=read();rb=read();rc=read();
		for(re int i=1;i<=ra;++i)a[i]=read();
		for(re int i=1;i<=rb;++i)b[i]=read();
		for(re int i=1;i<=rc;++i)c[i]=read();
		sort(a+1,a+ra+1);sort(b+1,b+rb+1);sort(c+1,c+rc+1);
		re int ans=6e18;
		ans=min(ans,calc(a,b,c,ra,rb,rc));
		ans=min(ans,calc(a,c,b,ra,rc,rb));
		ans=min(ans,calc(b,a,c,rb,ra,rc));
		ans=min(ans,calc(b,c,a,rb,rc,ra));
		ans=min(ans,calc(c,a,b,rc,ra,rb));
		ans=min(ans,calc(c,b,a,rc,rb,ra));
		printf("%lld\n",ans);
	}
}