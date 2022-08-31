#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<algorithm>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=1000000007;
int n,p[22]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67},f[22];
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
inline void insert(re int x){
	for(re int i=18;~i;--i)if(x&(1<<i)){if(!f[i]){f[i]=x;return;}else x^=f[i];}
}
int main(){
	n=read();
	for(re int i=1,x,l;i<=n;++i){
		x=read(),l=0;
		for(re int j=0;j<19;++j){
			re int sum=0;
			while(!(x%p[j]))x/=p[j],++sum;
			if(sum&1)l|=(1<<j);
		}
		insert(l);
	}
	for(re int i=0;i<19;++i)if(f[i])--n;
	printf("%d",ksm(2,n)-1);
}