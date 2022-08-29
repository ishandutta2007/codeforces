#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
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
int n,m,a[10002],cnt,d[2002],num,D[2002],b[10002],ans,k;
inline void ask(re int x){
	printf("? %d\n",x);
	fflush(stdout);
	for(re int i=1;i<=n;++i)d[i]=read();
}
inline void solve(re int l,re int r){
	r=min(r,n);
	re int len=r-l+1,nd=m-len/2;
	printf("? ");
	for(re int i=1;i<=n;++i)if(nd&&(i<l||i>r))printf("%d ",i),--nd;
	re int mid=l+r>>1;
	for(re int i=l;i<=mid;++i)printf("%d ",i);
	puts(""),fflush(stdout);
	ans^=read();
	nd=m-len/2;
	printf("? ");
	for(re int i=1;i<=n;++i)if(nd&&(i<l||i>r))printf("%d ",i),--nd;
	mid=l+r>>1;
	for(re int i=mid+1;i<=r;++i)printf("%d ",i);
	puts(""),fflush(stdout);
	ans^=read();
}
signed main(){
	k=n=read(),m=read();
	if((n&1)&&(!(m&1))){
		puts("-1");
		fflush(stdout);
		return 0;
	}
	if(n%2==0&&(m&1)&&(n<m*2)){
		re int lmt=(n-m)<<1;
		for(re int i=1;i<=n;i+=lmt)solve(i,i+lmt-1);
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	while(n>=2*m){
		printf("? ");
		for(re int i=1;i<=m;++i)++cnt,printf("%d ",cnt);
		puts("");
		fflush(stdout);
		ans^=read(),n-=m;
	}
	if(n==m){
		printf("? ");
		for(re int i=1;i<=m;++i)++cnt,printf("%d ",cnt);
		puts("");
		fflush(stdout);
		ans^=read();
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	else{
		if((n&1)||(n==k)){
			printf("? ");
			for(re int i=1;i<=m;++i)++cnt,printf("%d ",cnt);
			puts("");
			fflush(stdout);
			ans^=read();
			n-=m;
		}
		if(n){
			printf("? ");
			for(re int i=1;i<=n/2;++i)++cnt,printf("%d ",cnt);
			for(re int i=1;i<=m-(n>>1);++i)printf("%d ",i);
			puts("");
			fflush(stdout);
			ans^=read();
			printf("? ");
			for(re int i=1;i<=n/2;++i)++cnt,printf("%d ",cnt);
			for(re int i=1;i<=m-(n>>1);++i)printf("%d ",i);
			puts("");
			fflush(stdout);
			ans^=read();
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
}