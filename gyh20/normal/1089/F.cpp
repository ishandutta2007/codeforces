#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,a[12],sum[12],m,D[1000002],cnt,pri[1000002];
vector<int>A,B;
int main(){
	n=read();
	if((n&(-n))==n)return puts("NO"),0;
	m=n;
	for(re int i=2;i*i<=m;++i)if(n%i==0){
		pri[++cnt]=i;
		if(i*i!=n)pri[++cnt]=n/i;
	}
	if(cnt==0)return puts("NO"),0;
	for(re int i=cnt;i;--i)
		for(re int j=i-1;j;--j){
			if(__gcd(pri[i],pri[j])>1)continue;
			for(re int k=0;k<n/pri[i];++k){
				re int x=k*pri[i];
				if((n-1-x)%pri[j]==0){
					puts("YES");
					printf("2\n%d %d\n%d %d\n",k,n/pri[i],(n-1-x)/pri[j],n/pri[j]);
					exit(0);
				}
			}
		}
	puts("NO");
}