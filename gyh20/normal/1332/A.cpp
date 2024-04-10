#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int t,n,m,a,b,c,d,x,y,xx,yy,xxx,yyy;
signed main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read(),d=read();
		x=read();y=read();xx=read();yy=read();xxx=read();yyy=read();
		xx-=x;yy-=y;xxx-=x;yyy-=y;
		if((a||b)&&(!xx&&!xxx)){
			puts("NO");
			continue;
		}
		if((c||d)&&(!yy&&!yyy)){
			puts("NO");
			continue;
		}
		if((-(a-b)<xx)||(b-a>xxx)||(-(c-d)<yy)||(d-c>yyy)){
			puts("NO");
			continue;
		}
		puts("YES");
	}
}