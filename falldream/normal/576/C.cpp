#include<iostream>
#include<cstdio>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,X[MN+5],Y[MN+5],q[MN+5],q1[MN+5],q2[MN+5],q3[MN+5],q4[MN+5];

void Solve(int l,int r,int Lx,int Rx,int Ly,int Ry)
{
	if(l>r) return;
	//cout<<"Solve"<<l<<" "<<r<<" "<<Lx<<" "<<Rx<<" "<<Ly<<" "<<Ry<<endl;
	if(Rx-Lx<=1){for(int i=l;i<=r;++i)printf("%d ",q[i]);return;}
	int midx=Lx+Rx>>1,midy=Ly+Ry>>1;int num1=0,num2=0,num3=0,num4=0;
	for(int i=l;i<=r;++i)
	{
		if(X[q[i]]<=midx&&Y[q[i]]<=midy) q1[++num1]=q[i];
		else if(X[q[i]]<=midx) q2[++num2]=q[i];
		else if(Y[q[i]]<=midy) q4[++num4]=q[i];
		else q3[++num3]=q[i];	
	}
	int top=l-1;
	for(int i=1;i<=num1;++i) q[++top]=q1[i];
	for(int i=1;i<=num2;++i) q[++top]=q2[i];	
	for(int i=1;i<=num3;++i) q[++top]=q3[i];
	for(int i=1;i<=num4;++i) q[++top]=q4[i];
	Solve(l,l+num1-1,Lx,midx,Ly,midy);l+=num1;
	Solve(l,l+num2-1,Lx,midx,midy+1,Ry);l+=num2;
	Solve(l,l+num3-1,midx+1,Rx,midy+1,Ry);l+=num3;
	Solve(l,l+num4-1,midx+1,Rx,Ly,midy);l+=num4;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read(),q[i]=i;
	Solve(1,n,0,1e6,0,1e6);
	return 0;
}