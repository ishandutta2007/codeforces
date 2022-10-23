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
int t,n,m,a[1000002],A,B,R[1000002],stk[1000002],tp;
char s[1000002];
long long ans;
inline bool ck(re int x){
	int pos=n;
	while(a[pos]>x)--pos;
	for(re int i=1;i<=x;++i){
		while(a[pos]>x-i+1)--pos;
		if(pos<i)return 0;--pos;
	}return 1;
}
int main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();sort(a+1,a+n+1);
		for(re int i=n;~i;--i)
			if(ck(i)){
				printf("%d\n",i);
				break;
			}
	}
}