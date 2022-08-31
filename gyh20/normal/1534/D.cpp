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
int n,m,a[10002],cnt,d[2002],num,D[2002],b[10002];
inline void ask(re int x){
	printf("? %d\n",x);
	fflush(stdout);
	for(re int i=1;i<=n;++i)d[i]=read();
}
signed main(){
	n=read();
	ask(1);
	re int sum1=0,sum2=0;
	for(re int i=1;i<=n;++i)D[i]=d[i];
	for(re int i=1;i<=n;++i){
		sum1+=(d[i]&1);
		sum2+=(d[i]&1)^1;
	}
	if(sum1<sum2){
		for(re int i=1;i<=n;++i)
			if(D[i]&1){
				ask(i);
				for(re int j=1;j<=n;++j)if(d[j]==1)a[++cnt]=i,b[cnt]=j;
			}	
	}
	else{
		for(re int j=1;j<=n;++j)if(d[j]==1)a[++cnt]=1,b[cnt]=j;
		for(re int i=2;i<=n;++i)
			if(!(D[i]&1)){
				ask(i);
				for(re int j=1;j<=n;++j)if(d[j]==1)a[++cnt]=i,b[cnt]=j;
			}
	}
	printf("!\n");
	for(re int i=1;i<n;++i)printf("%d %d\n",a[i],b[i]);
	fflush(stdout);
}