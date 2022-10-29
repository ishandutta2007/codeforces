#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 100

using namespace std;
int i,j,m,p,k,n,t;
double power(double x,int y)
{
	  double sum=1.;
	  for (;y;y>>=1,x*=x) if (y&1) sum*=x;
	  return sum;
}
int main()
{
	 scanf("%d%d",&n,&t);
	 printf("%.10lf\n",n*power(1.000000011,t));
}