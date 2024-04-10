#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,ans,a,b,c,d,x,y;
signed main(){
	a=read();b=read();
	if(b<2*a)puts("NO");
	else{
		puts("YES");
		for(re int i=1;i<a;++i)printf("%d ",1),--b;printf("%d\n",b);
		printf("%d",b-1);
	}
}