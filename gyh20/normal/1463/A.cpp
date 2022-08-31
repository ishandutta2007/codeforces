#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<algorithm>
#define re register
using namespace std;
const int Mxdt=500000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<='0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a,b,c,t;
int main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read();
		if((a+b+c)%9)puts("NO");
		else{
			int d=min(min(a,b),c);
			if(d<(a+b+c)/9)puts("NO");
			else puts("YES");
		}
	}
}