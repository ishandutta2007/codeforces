#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<vector>
#define re register
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
#define gc getchar
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int z=1;
	while(y){
		if(y&1)z=1ll*z*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return z;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int n,a[200002],inv,ans,sum;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	ans=1;
	for(int i=n;i;--i)ans=100ll*ans%M*ksm(a[i],M-2)%M,add(sum,ans);
	printf("%d",sum);
	
}