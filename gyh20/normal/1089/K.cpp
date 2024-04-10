#include<bits/stdc++.h>
#define int long long
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int mx[4000002],sum[4000002],n,m,inf,A[300002],B[300002],ans;
char s[12];
inline void pu(re int p){
	mx[p]=max(mx[p<<1|1],mx[p<<1]+sum[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
inline void ins(re int p,re int l,re int r,re int x,re int y){
	if(l==r){sum[p]+=y,mx[p]+=y;return;}
	re int mid=l+r>>1;
	if(x<=mid)ins(p<<1,l,mid,x,y);
	else ins(p<<1|1,mid+1,r,x,y);
	pu(p);
}
inline void build(re int p,re int l,re int r){
	mx[p]=r;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
inline void ask(re int p,re int l,re int r,re int x){
	if(r<=x){
		ans=max(ans+sum[p],mx[p]);
		return;
	}
	re int mid=l+r>>1;
	ask(p<<1,l,mid,x);
	if(x>mid)ask(p<<1|1,mid+1,r,x);
}
signed main(){
	n=read(),inf=1e6,build(1,1,inf);
	for(re int i=1;i<=n;++i){
		scanf("%s",s+1);
		if(s[1]=='?'){
			re int x=read();ans=0,ask(1,1,inf,x);
			printf("%lld\n",ans-x);
		}
		else if(s[1]=='+'){
			A[i]=read(),B[i]=read();
			ins(1,1,inf,A[i],B[i]);
		}
		else{
			re int x=read();
			ins(1,1,inf,A[x],-B[x]);
		}
	}
}