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
int n,m,a[300002],b[300002],f[300002],mn[1200002],pre[300002],pos[1200002],ans1,ans2,inf1=1e12,inf2=1e18;
vector<int>V[300002];
inline void cg(re int p,re int l,re int r,re int x,re int y,re int z,re int o){
	if(l>=x&&r<=y){
	if(z<mn[p])mn[p]=z,pos[p]=o;return;	}
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y,z,o);
	if(y>mid)cg(p<<1|1,mid+1,r,x,y,z,o);
}
inline void ask(re int p,re int l,re int r,re int x){
	if(mn[p]<ans1)ans1=mn[p],ans2=pos[p];
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ask(p<<1,l,mid,x);
	else ask(p<<1|1,mid+1,r,x);
}
inline void Write(re int x){
	if(pre[x]^n)Write(pre[x]);
	printf("%lld ",x);
}
signed main(){
	n=read();
	memset(mn,127,sizeof(mn));
	for(re int i=1;i<=n;++i)a[i]=read(),V[i-a[i]].push_back(i);
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=n;~i;--i){
		if(i==n)f[i]=0,pre[i]=n;
		else ans1=inf2,ask(1,0,n,i),f[i]=ans1+1,pre[i]=ans2;
		if(i)cg(1,0,n,i+b[i]-a[i+b[i]],i+b[i],f[i],i);
	}
	if(f[0]>inf1)puts("-1");
	else{
		printf("%lld\n",f[0]);
		Write(0);
	}
}