#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,m,a[100002],cnt;
signed main(){
	n=read(),m=read();
	if(m<n||(m-n)&1){
		puts("-1");
		return 0;
	}
	if(n==0&&m==0){
		puts("0");
		return 0;
	}
	re int k=(m-n)>>1;
	if(n&k)
	a[1]=n,a[2]=k,a[3]=k,cnt=3;
	else if(k)
	a[1]=n^k,a[2]=k,cnt=2;
	else a[1]=n,cnt=1;
	printf("%lld\n",cnt);
	for(re int i=1;i<=cnt;++i)printf("%lld ",a[i]);
}