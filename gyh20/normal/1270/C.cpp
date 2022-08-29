#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
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
int n,a[100002],b,c,d,t;
signed main(){
	t=read();
	while(t--){
n=read();
b=c=0;
for(re int i=1;i<=n;++i){
	a[i]=read();
	b+=a[i];
	c^=a[i];
}
printf("2\n%lld %lld\n",c,b+c);

	}
}