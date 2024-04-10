#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t; 
}
int n,a[1000002],t,ans;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	puts("1 1");
	printf("%lld\n",-a[1]);
	if(n==1){puts("1 1");puts("0");puts("1 1");puts("0");return 0;}
	a[1]=0;
	printf("%d %lld\n",2,n);
	for(re int i=2;i<=n;++i){
		re int x=a[i]%n+n;
		x%=n;
		re int y=x*(n-1);
		a[i]+=y;
		printf("%lld ",y);
	}puts("");
	printf("1 %lld\n",n);
	for(re int i=1;i<=n;++i)printf("%lld ",-a[i]);
	
}