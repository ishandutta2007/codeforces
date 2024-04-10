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
int t,n,a,b,c,d;
int main(){
	t=read();
	while(t--){
		a=read();b=read();
		if(b>a){
			if((b-a)%2==1)puts("1");
			else puts("2");
		}
		else if(b==a)puts("0");
		else{
			if((b-a)%2==0)puts("1");
			else puts("2");
		}
	}
}