#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],rh[MN+5],en,q[MN+5],qn,u[MN+5],r[MN+5];
inline void ins(int*h,int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,i,j,x;
	n=read();qn=read();
	for(i=1;i<=qn;++i)u[q[i]=read()]=1;
	for(i=1;i<=n;++i)for(j=read();j--;)ins(h,x=read(),i),ins(rh,i,x);
	for(i=1;i<=qn;++i)for(j=rh[q[i]];j;j=e[j].nx)if(!u[e[j].t])u[q[++qn]=e[j].t]=1;
	for(i=1;i<=n;++i)if(u[i])for(j=h[i];j;j=e[j].nx)++r[e[j].t];
	for(x=qn,qn=0,i=1;i<=n;++i)if(u[i]&&!r[i])q[++qn]=i;
	for(i=1;i<=qn;++i)for(j=h[q[i]];j;j=e[j].nx)if(u[e[j].t]&&!--r[e[j].t])q[++qn]=e[j].t;
	if(qn<x)return puts("-1"),0;
	printf("%d\n",x);
	for(i=1;i<=x;++i)printf("%d ",q[i]);
}