#include<cstdio>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a,b,c,d;
int main(){
	t=read();
	while(t--){
		n=read();a=read();b=read();
		for(re int i=1;i<=a;++i)if(n/2+10>n)break;else n=n/2+10;
		if(b*10>=n)puts("YES");
		else puts("NO");
	}
}