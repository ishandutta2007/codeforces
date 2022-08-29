#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
} 
int n,m,t,a[100002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		if(n&1){
			re int x=n/2+1;printf("%d ",a[x]);
			for(re int i=1;i<=n/2;++i)printf("%d %d ",a[x+i],a[x-i]);
		}
		else{
			re int x=n/2;printf("%d ",a[x]);
			for(re int i=1;i<=n/2-1;++i)printf("%d %d ",a[x+i],a[x-i]);printf("%d ",a[n]);
			putchar('\n');
		}
	}
}