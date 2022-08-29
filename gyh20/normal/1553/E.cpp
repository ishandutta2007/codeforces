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
int t,n,m,a[1000002],b[1000002],ans[1000002],p[1000002],pos[1000002],cnt;
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=0;
		for(re int i=1;i<=n;++i){
			re int x=n-i+a[i];
			if(x>n)x-=n;
			++b[x];
		}cnt=0;
		for(re int i=1;i<=n;++i)
			if(b[i]+m*2>=n){
				for(re int j=1;j<=n;++j)p[j]=a[j],pos[a[j]]=j;
				re int num=0;
				for(re int j=1;j<=n;++j){
					re int x=i-(n-j);
					if(x<=0)x+=n;
					if(pos[x]!=j){
						re int X=x,Y=p[j];swap(p[j],p[pos[x]]),swap(pos[X],pos[Y]),++num;
					}
				}
				if(num<=m)ans[++cnt]=n-i;
			}
		sort(ans+1,ans+cnt+1);
		printf("%d ",cnt);
		for(re int i=1;i<=cnt;++i)printf("%d ",ans[i]);
		puts("");
	}
}