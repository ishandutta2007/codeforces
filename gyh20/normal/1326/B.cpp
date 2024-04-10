#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return f?-t:t;
}
int n,a[200002],b[200002],mx;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=1;i<=n;++i){
		a[i]=mx+b[i];
		printf("%d ",a[i]);
		mx=max(mx,a[i]);
	}
}