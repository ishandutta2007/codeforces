#include<bits/stdc++.h>
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
using namespace std;
int t,n,m,a[1000002],ans,x;
signed main(){
	t=read();
	while(t--){
		n=read();m=read();x=read();
		if(x<=n)printf("-1 %lld\n",m);
		else printf("%lld %lld\n",1ll,m*n>x?m:-1ll);
	}
}