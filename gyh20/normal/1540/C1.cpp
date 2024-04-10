#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,ans,cnt,b[1000002],c[100002],s,sum,f[102][10002],q,lmt[102];
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)c[i]=read();
	f[0][0]=1;
	for(re int i=1;i<n;++i)b[i]=read(),s+=b[i],sum+=s;
	q=read();
	while(q--){
		re int xx=read(),yy=xx;
		lmt[1]=xx;
		s=xx;
		for(re int i=2;i<=n;++i)s+=b[i-1],lmt[i]=lmt[i-1]+s;
		xx=xx*n+sum;
		for(re int i=1;i<=n;++i){
			for(re int k=0;k<=c[i];++k){
				for(re int j=k;j<=10000;++j)
					add(f[i][j],f[i-1][j-k]);
			}
			for(re int j=0;j<min(10001,lmt[i]);++j)f[i][j]=0;
		} 
		re int ss=0;
		for(re int j=max(xx,0);j<=10000;++j)add(ss,f[n][j]);
		printf("%d\n",ss);
	}
}