#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int n;
double xx,yy,x,y,mindis=2000000000,speed;
int main()
{
	xx=(double)read();
	yy=(double)read();
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=(double)read();
		y=(double)read();
		speed = (double)read();
		mindis=min(dis(xx,yy,x,y)/speed,mindis);
    }
    cout<<setprecision(20)<<fixed<<mindis;
    return 0;	
}