#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
long long n,m,jc[250002];
long long ans;
int main(){
n=read();
m=read();
jc[0]=1;
for(re int i=1;i<=n;++i)jc[i]=jc[i-1]*i%m;
for(re int i=1;i<=n;++i){
	ans+=(n-i+1)*jc[i]%m*(n-i+1)%m*jc[n-i]%m;
	ans%=m;
}
printf("%lld",ans);
}