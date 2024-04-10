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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
inline void work(re int x,re int y){
	if(x>n)return;
	for(re int i=0;i<=62&&n-x-i>=0;++i){
		if(y<=a[n-x-i]){
		//printf("aaa%lld %lld %lld\n",i,y,a[n-x-i]);
			for(re int j=i;~j;--j)printf("%lld ",x+j);
			work(x+i+1,y);
			return;
		}
		y-=a[n-x-i];
	}
}
signed main(){
	t=read();
	for(re int i=0;i<=100000;++i)a[i]=9e18;
	while(t--){
		n=read(),m=read();
		a[0]=b[0]=1;
		for(re int i=1;i<=min(n,62ll);++i)a[i]=b[i-1],b[i]=b[i-1]+a[i];
		if(m>a[n]&&n<=62)puts("-1");
		else{
			work(1,m);
			puts("");
		}
		
	}
}