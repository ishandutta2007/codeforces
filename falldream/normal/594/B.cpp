#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 100000
const double pi=acos(-1); 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,R,v;double C;
int main()
{
	n=read();R=read();v=read();C=2*pi*R; 
	for(register int i=1;i<=n;++i)
	{
		int s=read(),f=read(),d=f-s;
		double l=0,r=d+10,mid;
		for(int j=1;j<=100;++j)
		{
			mid=(l+r)/2.0;
			double M=(mid-int(mid/C)*C)/2.0;
			double D=mid+2*sin(2*M/C*pi)*R;
			if(D>=d) r=mid;
			else l=mid;
		}
		printf("%.10lf\n",(l+r)/2.0/v);
	}
	return 0;
}