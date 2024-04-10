#include<cstdio>
#include<algorithm>
#include<iostream>
#define re register
using namespace std;
#define int long long
int n,a[100002],m,k;
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
signed main() {
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=31;i>=0;--i){
		int opt=0;
		int pos=0;
		for(re int j=1;j<=n;++j)if(a[j]&(1ll<<i))++opt,pos=j;
		if(opt==1){swap(a[1],a[pos]);break;
		}
	}
	for(re int i=1;i<=n;++i)printf("%lld ",a[i]);
}