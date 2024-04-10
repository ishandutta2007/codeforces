#include<bits/stdc++.h>
using namespace std;
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
int t,n,a,b,c,d,e,f,ans,x,y;
int main(){
	t=read();
	while(t--){
		ans=1e9;
		a=read();
		b=read();
		c=read();
		for(re int i=1;i<=10000;++i){
			for(re int j=i;j<=20000;j+=i){
				int tmp=c/j;
				if(abs(tmp*j-c)<abs((tmp+1)*j-c))x=tmp*j;
				else x=(tmp+1)*j;
				if(abs(i-a)+abs(j-b)+abs(x-c)<ans){
					ans=abs(i-a)+abs(j-b)+abs(x-c);
					d=i,e=j,f=x;
				}
			}
		}
		printf("%d\n%d %d %d\n",ans,d,e,f);
	}
}