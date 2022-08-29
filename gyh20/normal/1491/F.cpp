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
int t,n,m,a[1000002],cnt,head[1000002],b[1000002],lst,ans[1000002],vis[2002],sss,VV;
inline int ask(re int x,re int l,re int r){
	printf("? %d %d\n",1,r-l+1);
	printf("%d\n",x);
	for(re int i=l;i<=r;++i)printf("%d ",i);
	puts("");
	fflush(stdout);
	re int s=0;
	scanf("%d",&s);
	++sss;
	if(sss>n+log2(n))exit(1);
	return s;
}
inline void print(re int pos){
	re int num=0;
	ans[++num]=pos;
	if(pos^lst)ans[++num]=lst;
	re int xx=0;
	for(re int i=lst+1;i<n;++i){
		re int xxx=ask(lst,i,i);
		xx+=xxx;if(xxx!=0)ans[++num]=i;
	}
	if(xx!=VV)ans[++num]=n;
	memset(vis,0,sizeof(vis));
	for(re int i=1;i<=num;++i)vis[ans[i]]=1;
	num=0;
	for(re int i=1;i<=n;++i)if(!vis[i])ans[++num]=i;
	printf("! %d ",num);
	for(re int i=1;i<=num;++i)printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
}
inline void bs(re int l,re int r){
	re int pos=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(ask(lst,1,mid)!=0)r=mid-1,pos=mid;
		else l=mid+1;
	}
	if(!pos)print(lst);
	else print(pos);
}
signed main(){
	t=read();
	while(t--){
		sss=0;
		n=read();
		re int pos=1,la=ask(1,2,n);
		if(la!=0){VV=la;
			lst=1;
			print(1);
			continue;
		}
		for(re int i=2;i<=n;++i){
			re int x=ask(i,i+1,n);VV=x;
			lst=i;
			if(x!=0){bs(1,i-1);break;}
		}
	//	printf("aaa%d\n",sss);
	}
}