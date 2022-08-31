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
int t,n,m,k,x,lst;
signed main(){
	n=read();m=read();k=read();
	for(re int i=1;i<=k;++i)x=read(),x=read();
	printf("%d\n",n+m+n*m-1);
	for(re int i=1;i<=n;++i){
		putchar('U');
	}
	for(re int i=1;i<=m;++i)putchar('L');
	for(re int i=1;i<=n;++i){
		if(i&1){
			for(re int i=1;i<m;++i)putchar('R');
		}
		else for(re int i=1;i<m;++i)putchar('L');
		if(i!=n)putchar('D');
	}
}