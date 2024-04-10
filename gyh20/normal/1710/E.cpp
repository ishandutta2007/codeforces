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
int n,m,n1,n2,a[500002],b[500002],px[500002],py[500002],sx[500002],sy[500002];
inline int sum(re int x,re int y,re bool z){
	re int tmp=0;
	if(px[x]<y){
		if(z){
			if(n1>x&&n2>y)tmp=1;
			if(n1<=x&&n2<=y&&n2<=px[n1])tmp=1;
		}
		return 1ll*py[y]*y+sx[x]-sx[py[y]]+1ll*(n-x)*(m-y)-tmp;
	}
	else{
		if(z){
			if(n1<=x&&n2<=y)tmp=1;
			if(n1>x&&n2>y&&n2>px[n1])tmp=1;
		}
		return 1ll*x*y+(1ll*(py[y]-x)*m-sx[py[y]]+sx[x])+1ll*(n-py[y])*(m-y)-tmp;
	}
}
inline bool check(re int x){
	px[0]=m,py[0]=n;
	for(re int i=1;i<=n;++i){
		px[i]=px[i-1];
		while(px[i]&&a[i]+b[px[i]]>x)--px[i];
	}
	for(re int i=1;i<=n;++i)sx[i]=sx[i-1]+px[i];
	for(re int i=1;i<=m;++i){
		py[i]=py[i-1];
		while(py[i]&&a[py[i]]+b[i]>x)--py[i];
	}
	re int a0=max(sx[n],1ll*n*m-sx[n]),a1=max(sx[n]-(n2<=px[n1]),1ll*n*m-sx[n]-(n2>px[n1]));
	re int p=1;
	for(int i=1;i<=n;++i){
		while(p<m&&sum(i,p,0)<=sum(i,p+1,0))++p;
		a0=max(a0,sum(i,p,0));
	}
	p=1;
	for(re int i=1;i<=n;++i){
		while(p<m&&sum(i,p,1)<=sum(i,p+1,1))++p;
		a1=max(a1,sum(i,p,1));
	}
	return a0!=a1+1;
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=m;++i)b[i]=read();
	n1=a[1],n2=b[1],sort(a+1,a+n+1),sort(b+1,b+m+1),n1=lower_bound(a+1,a+n+1,n1)-a,n2=lower_bound(b+1,b+m+1,n2)-b;
	re int l=a[1]+b[1],r=a[n1]+b[n2],pos=a[n1]+b[n2];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,pos=mid;
		else l=mid+1;
	}
	printf("%lld",pos);
}