#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B;
char s[1000002];
int main(){
	scanf("%d",&n);
	if(n<1200)puts("1200");
	else if(n<1400)puts("1400");
	else if(n<1600)puts("1600");
	else if(n<1900)puts("1900");
	else if(n<2100)puts("2100");
	else if(n<2300)puts("2300");
	else if(n<2400)puts("2400");
	else if(n<2600)puts("2600");
	else puts("3000");
}