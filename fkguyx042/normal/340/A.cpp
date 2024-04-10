#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b,x,y;
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main()
{ scanf("%d%d%d%d",&x,&y,&a,&b);
  n=x*y/gcd(x,y);
  printf("%d\n",b/n-(a-1)/n);
}