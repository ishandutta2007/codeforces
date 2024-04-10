#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int c,v0,v1,a,l,s,v;
int main(){
	c=read(),v0=read(),v1=read(),a=read(),l=read();
	for(re int i=1;i<=114514;++i){
		s+=v0,v0+=a,v0=min(v0,v1);
		if(s>=c){
			printf("%d\n",i);
			return 0;
		}
		s-=l;
	}
}