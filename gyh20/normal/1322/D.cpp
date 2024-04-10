#include<bits/stdc++.h>
#define re register 
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,f[2002][2002],a[2002],m,b[2002],c[4002],ans;
inline void gmx(re int&x,re int y){y>x&&(x=y);}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=1;i<=n+m;++i)c[i]=read();
	memset(f,-0x3f,sizeof(f));
	for(re int i=1;i<=m;++i)f[i][0]=0;
	for(re int i=n;i;--i){
		for(re int j=n;~j;--j){
			re int x=f[a[i]][j]+c[a[i]]-b[i],X=a[i],Y=j+1;
			while(X<=m&&Y)gmx(f[X][Y],x),x+=(Y>>1)*c[X+1],Y>>=1,++X;gmx(f[X][Y],x);
		}
		for(re int j=1;j<=m;++j)gmx(f[j][0],f[j-1][0]);
	}
	for(re int i=1;i<=m;++i)
		for(re int j=0;j<=n;++j){
			re int X=j>>1,pp=i+1,s=f[i][j];
			while(X)s+=X*c[pp],++pp,X>>=1;
			ans=max(ans,s);
		}
	printf("%d",ans);
}