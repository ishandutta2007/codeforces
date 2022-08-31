#include<bits/stdc++.h>
#define re register
using namespace std;
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
int t,n,a[100002],b[100002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i)b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(re int i=1;i<=n;++i)printf("%d ",a[i]);
		putchar('\n');
		for(re int i=1;i<=n;++i)printf("%d ",b[i]);
		putchar('\n');
	}
}