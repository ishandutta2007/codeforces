#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a,b,c,d;
char s[200002];
int main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read(),d=read();
		if(a==c)printf("%d\n",abs(b-d));
		else if(b==d)printf("%d\n",abs(a-c));
		else printf("%d\n",abs(a-c)+abs(b-d)+2);
	}
}