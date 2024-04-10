#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,A[102],B[102],n,mx1,mx2,m;
int main(){
	t=read();
	while(t--){
		n=read(),m=read();mx1=mx2=0;
		for(re int i=1;i<=m;++i){
			A[i]=read(),B[i]=read();
			mx1=max(mx1,A[i]),mx2=max(mx2,B[i]);
		}
		if(mx1+mx2>n)puts("IMPOSSIBLE");
		else{
			for(re int i=1;i<=mx1;++i)putchar('R');
			for(re int i=1;i<=n-mx1;++i)putchar('W');
			puts("");
		}
	}
}