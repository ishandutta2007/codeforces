#include<cstdio>
#include<algorithm>
#define re register
#define ll long long
using namespace std;
const int Mxdt=1000000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int n,fa[1000002],f[1000002],ans,g[1000002];
ll s[1000002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)s[i]=read();
	for(re int i=2;i<=n;++i)fa[i]=read();
	for(re int i=n;i;--i)s[fa[i]]+=s[i];
	for(re int i=n;i;--i){
		re ll tmp=s[1]/__gcd(s[1],s[i]);
		if(tmp<=n)++f[tmp];
	}
	for(re int i=n;i;--i)for(re int j=i+i;j<=n;j+=i)f[j]+=f[i];g[1]=1;
	for(re int i=1;i<=n;++i)if(f[i]==i){for(re int j=i+i;j<=n;j+=i)add(g[j],g[i]);add(ans,g[i]);}
	printf("%d",ans);
}