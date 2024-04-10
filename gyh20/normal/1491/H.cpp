#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[400002],B,bl[400002],ed[1002],st[1002],mx[1002],tg[1002],b[400002];
inline void rebuild(re int x){
	mx[x]=1;
	for(re int i=st[x];i<=ed[x];++i)a[i]=max(1,a[i]-tg[x]),b[i]=(a[i]<st[x]?a[i]:b[a[i]]),mx[x]&=a[i]==b[i];
	tg[x]=0;
}
inline int lca(re int x,re int y){
	while(b[x]^b[y])x>y?x=max(1,b[x]-tg[bl[x]]):y=max(1,b[y]-tg[bl[y]]);
	while(x^y)x>y?x=max(1,a[x]-tg[bl[x]]):y=max(1,a[y]-tg[bl[y]]);
	return x;
}
int main(){
	n=read(),m=read(),B=sqrt(n),a[1]=b[1]=bl[1]=ed[1]=1;
	for(re int i=2;i<=n;++i)a[i]=read(),bl[i]=(i-1)/B+1,ed[bl[i]]=i;
	for(re int i=n;i;--i)st[bl[i]]=i;
	for(re int i=1;i<=bl[n];++i)rebuild(i);
	while(m--){
		re int o=read(),l=read(),r=read();
		if(o==1){
			re int x=read();
			if(bl[l]==bl[r]){
				for(re int i=l;i<=r;++i)a[i]=max(1,a[i]-x);
				rebuild(bl[l]);
			}
			else{
				for(re int i=l;i<=ed[bl[l]];++i)a[i]=max(1,a[i]-x);
				rebuild(bl[l]);
				for(re int i=bl[l]+1;i<bl[r];++i){
					tg[i]+=x,tg[i]=min(tg[i],n);
					if(!mx[i])rebuild(i);
				}
				for(re int i=st[bl[r]];i<=r;++i)a[i]=max(1,a[i]-x);
				rebuild(bl[r]);
			}
		}
		else printf("%d\n",lca(l,r));
	}
}