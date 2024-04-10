#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[52][52],g[52][52],h[52][52];
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
inline int C(re int x,re int y){
	re int s=1;
	for(re int i=x-y+1;i<=x;++i)s=1ll*s*i%M;
	for(re int i=1;i<=y;++i)s=1ll*s*ksm(i,M-2)%M;
	return s;
}
inline void Upd(re int x,re int y,re int z){
	memset(h,0,sizeof(h));
	for(re int k=1;k*x<=50&&k*y<=50;++k)
		for(re int i=0;i+k*x<=50;++i)
			for(re int j=0;j+k*y<=50;++j)
				add(h[i+k*x][j+k*y],1ll*g[i][j]*C(z+k-1,k)%M);
	for(re int i=0;i<=50;++i)for(re int j=0;j<=50;++j)add(g[i][j],h[i][j]);
}
inline int calc(re int x,re int y){
	if(~f[x][y])return f[x][y];
	if(y==0)return x==0;
	if(x==0)return y==0;
	--x,--y;re int s=0;
	for(re int i=y;i<=x;++i)
		for(re int j=y;j<=x;++j)
			if(i==y||j==y)
				for(re int a=0;a<=x;++a)
					add(s,1ll*calc(a,i)*calc(x-a,j)%M);
	Upd(x+1,y+1,s),s=g[x+1][y+1];
	return f[x+1][y+1]=s;
}
int main(){
	memset(f,-1,sizeof(f)),n=read(),m=read()-1,g[0][0]=1;
	for(re int i=0;i<=50;++i)for(re int j=1;j<=50;++j)calc(i,j);
	printf("%d",calc(n,m));
}