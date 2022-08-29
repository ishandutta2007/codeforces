#include<bits/stdc++.h>
#include<windows.h>
#define re register
using namespace std;
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
int t,a,b,c,ans,d,e,f,g,h,k;
int main(){
	t=read();
	while(t--){
		a=read();
		b=read();
		f=g=h=k=0;
		c=read();
		if(b>c)swap(b,c);
		f+=min(a-b-1,c-1)<0?0:min(a-b-1,c-1);
		if(a-b-1>c-1)k+=a-b-c+1;
		else if(a-b)++k;
		f+=min(a-c-1,b-1)<0?0:min(a-c-1,b-1);
		if(a-c-1>b-1)h+=a-b-c+1;
		else if(a-c)++h;
		if(b+c>a)g=a-1;
		else {
			g=c-b;
			g+=min(b-1,a-c)*2;
		}
		printf("%d %d\n",(a-f-min(h,k))<1?1:(a-f-min(h,k)),g+1);
	}
}