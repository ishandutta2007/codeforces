#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int a[102],n,f[2][102];
int main(){
	int A=read(),B=read();
	A=min(A,B);
	re int ans=1;
	for(re int i=1;i<=A;++i)ans*=i;
	printf("%d",ans);
}