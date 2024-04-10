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
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,f[102][102][2];
char s[1000002];
inline int calc(re int x,re int y,re int z){
	if(x==0&&y==0)return z==0;
	if(~f[x][y][z])return f[x][y][z];
	re int s=0;
	if(x){
		if(!calc(x-1,y,z^(y&1)^1))s=1;
	}
	if(y){
		if(!calc(x,y-1,z^((y-1)&1)))s=1;
	}
	return f[x][y][z]=s;
}
int main(){
	t=read();
	memset(f,-1,sizeof(f));
	while(t--){
		n=read();
		re int n0=0,n1=0;
		for(re int i=1;i<=n;++i){
			a[i]=read()%2;
			if(a[i]==0)++n0;
			else ++n1;
		}
		puts(calc(n0,n1,0)?"Alice":"Bob");
	}
}