#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
#define M 998244353
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,k,x,jc[400002],ans;
signed main(){
	n=read();jc[0]=1;for(re int i=1;i<=n*2;++i)jc[i]=jc[i-1]*10%M;
	for(re int i=1;i<=n;++i){
		ans=0;
		if(i==n)ans+=10;
		else if(i==n-1)ans+=180;
		else{
		ans+=(n-i-1)*jc[n-i-2]%M*810ll%M;
		ans+=jc[n-i-1]*180ll%M;
		}
		printf("%lld ",ans%M);
	}
}