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
char s[1002];
signed main(){
	n=read();
	for(re int i=2;i<n;++i)if(n%i==0)return printf("%d%d",i,n/i),0;
}