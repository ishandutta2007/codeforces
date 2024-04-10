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
int t,n,m,a[1000002],cnt,ans[502][502];
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		re int px=i,py=i;
		for(re int j=1;j<=a[i];++j){
			ans[px][py]=a[i];
			if(py>1&&!ans[px][py-1])--py;
			else ++px;
		}
	}
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=i;++j)printf("%d ",ans[i][j]);
		puts("");
	}
}