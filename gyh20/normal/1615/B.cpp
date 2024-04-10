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
inline int calc(re int x,re int y){
	return x/(y<<1)*y+max(0,x%(y<<1)-y+1);
}
int main(){
	t=read();
	while(t--){
		A=read(),B=read();ans=0;
		for(re int i=1;i<400000;i<<=1)
			ans=max(ans,calc(B,i)-calc(A-1,i));
		printf("%d\n",B-A+1-ans);
	}
}