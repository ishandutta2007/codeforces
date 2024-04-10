#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=1000000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
int t,n,m,a[1000002],ans,A,B,V[1000002],f[1000002],mx[4000002],c[500002];
long long s[1000002],O[1000002];
inline void add(re int x,re int y){for(;x<=n+1;x+=x&(-x))c[x]=max(c[x],y);}
inline int ask(re int x,re int s=-1e9){for(;x;x^=x&(-x))s=max(s,c[x]);return s;}
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),s[i]=s[i-1]+a[i],O[i]=s[i];
		for(re int i=0;i<=n+1;++i)c[i]=V[i]=-1e9;
		O[n+1]=s[n+1]=0;sort(O+1,O+n+2);
		for(re int i=1;i<=n+1;++i)s[i]=lower_bound(O+1,O+n+2,s[i])-O;
		add(s[n+1],0),V[s[n+1]]=0;
		for(re int i=1;i<=n;++i){
			f[i]=V[s[i]];
			f[i]=max(f[i],ask(s[i]-1)+i);
			f[i]=max(f[i],f[i-1]-1);
			add(s[i],f[i]-i),V[s[i]]=max(V[s[i]],f[i]);
		}
		printf("%d\n",f[n]);
	}
}