#include<cstdio>
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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans[1000002],A,B,mn,v[1000002],v1[1000002],stk[1000002],tp;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=0;
		for(re int i=1;i<=n;++i)a[i]=read(),++v[a[i]];
		mn=0;
		while(v[mn])++mn;tp=0;
		re int pos=0;
		for(re int i=1;i<=n;++i){
			++v1[a[i]],stk[++tp]=a[i];
			while(v1[pos])++pos;
			if(pos==mn){
				ans[++m]=mn;
				for(re int j=1;j<=tp;++j)--v1[stk[j]],--v[stk[j]];
				mn=0,tp=0;
				while(v[mn])++mn;
				pos=0;
			}
		}
		printf("%d\n",m);
		for(re int i=1;i<=m;++i)printf("%d ",ans[i]);
		puts("");
	}
}