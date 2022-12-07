#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<ctime>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define _max(a,b) (a>b?a:b)
#define _min(a,b) (a<b?a:b)

using namespace std;
template<class T>
inline void read(T& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x*=-1;
}
int n;
double h,s,out[23333];
int main()
{
	scanf("%d%lf",&n,&h);
	s=h/n;
	double last=1;
	out[0]=h;
	for(int i=1;i<n;i++)
	{
		double x,a=-1/h,b=2*last,c=-s;
		x=(-b+sqrt(b*b-4*a*c))/2/a; 
		out[i]=out[i-1]-x;
		last-=x/h;
	}
	for(int i=n-1;i;i--)
		printf("%.10lf ",out[i]);
}