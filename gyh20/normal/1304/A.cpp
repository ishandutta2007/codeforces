#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
	t=(t<<3)+(t<<1)+v-48;
	v=getchar();}
	return t;
}
int t,n,f[200002],k,cnt,tot,a,b,c,d;
int main(){
t=read();
while(t--){
	a=read();
	b=read();
	c=read();
	d=read();
	if((b-a)%(c+d)==0)printf("%d\n",(b-a)/(c+d));
	else puts("-1");
}
}