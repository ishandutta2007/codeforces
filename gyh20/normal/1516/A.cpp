#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,a[102],pos;
int main(){
	int t=read();
	while(t--){
		n=read(),k=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		pos=1;
		while(k--){
			while(pos<=n&&(!a[pos]))++pos;
			if(pos>n)break;
			--a[pos],++a[n];
		}
		for(re int i=1;i<=n;++i)printf("%d ",a[i]);
		puts("");
	}
}