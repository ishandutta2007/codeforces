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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,B,a[100002],f[402][100002],bl[100002],lst[100002],b[100002],ed[402],st[402],val[100002],sum,g[100002],tg[402];
inline void Add(re int l,re int r,re int x){
	if(l>r)return;
	if(bl[l]==bl[r]){
		for(re int i=l;i<=r;++i){
			add(f[bl[l]][val[i]],M-g[i-1]);
			add(f[bl[l]][val[i]+x],g[i-1]);
			if(val[i]+tg[bl[l]]==m&&x==1)add(sum,M-g[i-1]);
			if(val[i]+tg[bl[l]]==m+1&&x==-1)add(sum,g[i-1]);
			val[i]+=x;
		}
	}
	else{
		for(re int i=l;i<=ed[bl[l]];++i){
			add(f[bl[l]][val[i]],M-g[i-1]);
			add(f[bl[l]][val[i]+x],g[i-1]);
			if(val[i]+tg[bl[l]]==m&&x==1)add(sum,M-g[i-1]);
			if(val[i]+tg[bl[l]]==m+1&&x==-1)add(sum,g[i-1]);
			val[i]+=x;
		}
		for(re int i=bl[l]+1;i<bl[r];++i)
			if(x==-1)--tg[i],add(sum,f[i][m-tg[i]]);
			else add(sum,M-f[i][m-tg[i]]),++tg[i];
		for(re int i=st[bl[r]];i<=r;++i){
			add(f[bl[r]][val[i]],M-g[i-1]);
			add(f[bl[r]][val[i]+x],g[i-1]);
			if(val[i]+tg[bl[r]]==m&&x==1)add(sum,M-g[i-1]);
			if(val[i]+tg[bl[r]]==m+1&&x==-1)add(sum,g[i-1]);
			val[i]+=x;
		}
	}
}
int main(){
	n=read(),m=read(),B=500;
	for(re int i=1;i<=n;++i)bl[i]=(i-1)/B+1,a[i]=read(),lst[i]=b[a[i]],b[a[i]]=i,ed[bl[i]]=i;
	for(re int i=n;i;--i)st[bl[i]]=i;g[0]=1;
	for(re int i=1;i<=n;++i){
		add(f[bl[i]][0],g[i-1]),add(sum,g[i-1]);
		re int x=lst[lst[i]],y=lst[i];
		Add(x+1,y,-1),Add(y+1,i,1),g[i]=sum;
	}
	printf("%d",g[n]);
}