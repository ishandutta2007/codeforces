#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;
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
int R[252],C[252],a[252][252],n,m,b[252][252],Qx[100002],Qy[100002],hd,tl;
char v1[100002],v2[100002];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			a[i][j]=read(),R[i]=max(R[i],a[i][j]),C[j]=max(C[j],a[i][j]);
	for(re int i=1;i<=n;++i)++v1[R[i]];
	for(re int i=1;i<=m;++i)++v2[C[i]];
	re int X=0,Y=0;hd=1;
	for(re int i=n*m;i;--i){
		if(v1[i])++X;
		if(v2[i])++Y;
		if(v1[i]||v2[i])b[X][Y]=i;
		else b[Qx[hd]][Qy[hd]]=i,++hd;
		if(v1[i])for(re int j=Y-1;j;--j)Qx[++tl]=X,Qy[tl]=j;
		if(v2[i])for(re int j=X-1;j;--j)Qx[++tl]=j,Qy[tl]=Y;
	}
	for(re int i=1;i<=n;++i,puts(""))
		for(re int j=1;j<=m;++j)
			printf("%d ",b[i][j]);
}