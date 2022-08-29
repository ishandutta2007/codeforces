#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[2002],sum,G;
bitset<200002>B;
int main(){
	n=read(),B[0]=1;
	for(re int i=1;i<=n;++i){
		a[i]=read(),sum+=a[i];
		B|=(B<<a[i]);
	}
	if((sum&1)||(!B[sum>>1]))return puts("0"),0;
	G=a[1];
	for(re int i=2;i<=n;++i)G=__gcd(G,a[i]);
	for(re int i=1;i<=n;++i)a[i]/=G;
	for(re int i=1;i<=n;++i){
		if(a[i]&1){
			printf("1\n%d",i);
			return 0;
		}
	}
}