#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
using namespace std;
int n,m,a,b,c,d,t,ans;
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		if(m<n*2)puts("-1 -1");
		else printf("%d %d\n",n,n*2);
	}
}