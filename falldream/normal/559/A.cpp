#include<iostream>
#include<cstdio>
#include<cmath>
const double sq=sqrt(3);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double X[10],Y[10],ans=0;
int a[10];
int main()
{
	for(int i=1;i<=6;++i) a[i]=read();
	X[0]=Y[0]=0;
	X[1]=(double)a[1]/2,Y[1]=X[1]*sq;
	X[2]=X[1]+a[2];Y[2]=Y[1];
	X[3]=X[2]+(double)a[3]/2,Y[3]=Y[2]-(double)a[3]/2*sq;
	X[4]=X[3]-(double)a[4]/2,Y[4]=Y[3]-(double)a[4]/2*sq;
	X[5]=X[4]-a[5];Y[5]=Y[4];
	X[6]=X[0],Y[6]=Y[0];
	for(int i=0;i<6;++i) ans+=X[i]*Y[i+1]-X[i+1]*Y[i];
	if(ans<0) ans=-ans;
	printf("%d\n",int(ans*2/sq+0.1));
	return 0;
}