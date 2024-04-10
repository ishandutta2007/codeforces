#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	if(y<0)return 0;
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,A[1000002],B[1000002],C[1000002],f[1000002];
long long ans;
int main(){
	n=read();
	while(n--){
		re int x=read();
		add(A[x],1ll*x*x%M),add(B[x],x),add(C[x],1);
	}
	for(re int i=1;i<=1000000;i*=10)for(re int j=1000000-i;~j;--j)if((j/i)%10!=9)add(A[j],A[j+i]),add(B[j],B[j+i]),add(C[j],C[j+i]);
	for(re int i=0;i<=1000000;++i)f[i]=1ll*A[i]*ksm(2,C[i]-1)%M,add(f[i],(1ll*B[i]*B[i]+M-A[i])%M*ksm(2,C[i]-2)%M);
	for(re int i=1;i<=1000000;i*=10)for(re int j=0;j<1000000-i;++j)if((j/i)%10!=9)add(f[j],M-f[j+i]);
	for(re int i=0;i<1000000;++i)ans^=1ll*f[i]*i;
	printf("%lld",ans);
}