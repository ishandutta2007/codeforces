#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}

int t,n,m;
signed main(){
	t=read();
	while(t--){
		n=read();m=read();
		m=(1+2*m-1)*m/2;
		if(n>=m&&(!((n-m)&1)))puts("YES");
		else puts("NO");
	}
}