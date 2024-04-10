#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,k,mx,lst;
signed main(){
	k=read();
	puts("3 3");
	printf("%d %d %d\n",262143,k,0);
	printf("%d %d %d\n",131072,262143,k);
	printf("%d %d %d",0,0,262143);
}