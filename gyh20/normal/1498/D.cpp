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
int t,n,m,a[1000002],b[1000002],c[1000002],ans[100002];
long double d[1000002];
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read(),c[i]=read();
	memset(ans,-1,sizeof(ans));ans[0]=0;
	for(re int i=1;i<=n;++i){
		if(a[i]==1){
			b[i]=(b[i]+99999)/100000;
	}
		for(re int j=m;~j;--j)
			if(ans[j]>-1){
				if(j==0&&a[i]==2)continue;
				re int x=j;
				re int num=0;
				while(1){
					++num;
					if(num>c[i])break;
					if(a[i]==1)x=x+b[i];
					else x=(x*b[i]+99999)/100000;
					re int tmp=x;x=tmp;
					if(tmp>m)break;
					if(ans[tmp]>-1)break;
					ans[tmp]=i;
				}
			}
		
	}
	for(re int i=1;i<=m;++i)printf("%lld ",ans[i]);
}