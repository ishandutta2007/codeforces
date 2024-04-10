#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],sum[1000002],sum1[1000002];
inline int find(re int *p,re int l,re int r,re int x){
	re int pos=l;
	while(l<=r){
		re int mid=l+r>>1;
		if(p[mid]<=x)pos=mid,l=mid+1;
		else r=mid-1;
	}
	return pos;
}
inline int find1(re int *p,re int l,re int r,re int x){
	re int pos=r;
	while(l<=r){
		re int mid=l+r>>1;
		if(p[mid]>=x)pos=mid,r=mid-1;
		else l=mid+1;
	}
	return pos;
}
map<int,int>v;
signed main(){
	t=read();
	while(t--){
		v.clear();
		n=read(),m=read();
		a[0]=b[0]=-2e9,a[n+1]=b[m+1]=2e9;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int j=1;j<=m;++j)b[j]=read(),v[b[j]]=1;
		for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+v[a[i]];
		sum1[n+1]=0;
		for(re int i=n;i;--i)sum1[i]=sum1[i+1]+v[a[i]];
		re int pa=n+1,pb=m+1,ans1=0,ans2=0;
		for(re int i=1;i<=n&&pa==n+1;++i)if(a[i]>0)pa=i;
		for(re int j=1;j<=m&&pb==m+1;++j)if(b[j]>0)pb=j;
		for(re int i=pb-1;i;--i){
			re int xx=find1(a,0,pa,b[i]);
			if(xx==pa)continue;
			re int num=pa-xx;
			re int yy=find(b,0,pb-1,b[i]+num-1);
			re int ss=yy-i+1;
			if(xx)ss+=sum[xx-1];
			ans1=max(ans1,ss);
		}
		for(re int i=pb;i<=m;++i){
			re int xx=find(a,pa-1,n+1,b[i]);
			if(xx<pa)continue;
			re int num=xx-pa+1;
			re int yy=find1(b,pb,m+1,b[i]-num+1);
			re int ss=i-yy+1;
			if(xx)ss+=sum1[xx+1];
			ans2=max(ans2,ss);
		}
		printf("%d\n",ans1+ans2);
	}
}