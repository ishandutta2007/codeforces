#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,ans,a[1000002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)printf("%d ",(i&1)?read():-read());
		puts("");
	}
}