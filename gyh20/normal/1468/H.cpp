#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	//
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read() {
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,k,b[200002],vis[200002],t;
//c[0]:a[i]<a[lst] c[1]:a[i]>=a[lst]
int main() {
	t=read();
	while(t--) {
		n=read(),m=read(),k=read();
		for(re int i=1;i<=n;++i)vis[i]=0;
		for(re int i=1;i<=k;++i)b[i]=read(),vis[b[i]]=1;
		if((n-k)%(m-1)){
			puts("NO");
			continue;
		}
		if(n==k){
			puts("YES");
			continue;
		}
		int x=n-k,sum=0,ia=0;x>>=1;
		for(re int i=1;i<=n;++i){
			if(!vis[i])++sum;
			else if(sum>=(m-1)/2&&n-k-sum>=(m-1)/2){
				ia=1;
			}
		}
		if(ia)puts("YES");
		else puts("NO");
	}
}