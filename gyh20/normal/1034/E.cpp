#include<cstdio>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,A[1<<21],B[1<<21],pw[25];
char s1[1<<22],s2[1<<22];
signed main(){
	scanf("%lld%s%s",&n,s1,s2);
	for(re int i=0;i<(1<<n);++i)A[i]=s1[i]&15,B[i]=s2[i]&15;
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=pw[i-1]*4;
	for(re int i=0;i<(1<<n);++i)A[i]=A[i]*pw[__builtin_popcount(i)],B[i]=B[i]*pw[__builtin_popcount(i)];
	for(re int i=1;i<(1<<n);i<<=1)
		for(re int j=0;j<(1<<n);++j)
			if(j&i)
				A[j]+=A[j^i],B[j]+=B[j^i];
	for(re int i=0;i<(1<<n);++i)A[i]*=B[i];
	for(re int i=1;i<(1<<n);i<<=1)
		for(re int j=0;j<(1<<n);++j)
			if(j&i)
				A[j]-=A[j^i];
	for(re int i=0;i<(1<<n);++i)A[i]/=pw[__builtin_popcount(i)],printf("%lld",(A[i]%4+4)%4);
}