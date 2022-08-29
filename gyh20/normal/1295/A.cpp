#include<bits/stdc++.h>
#define re register
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
int n,t;
int main(){
	t=read();
	while(t--){
		n=read();
		if(n&1)putchar('7');
		else putchar('1');
		for(re int i=1;i<=n/2-1;++i)putchar('1');
		
		putchar('\n');	
	}
}