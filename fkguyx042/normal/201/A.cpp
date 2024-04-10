#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[100001],x;
int main()
{
  scanf("%d",&x);
  if (x==3) printf("5\n");
  else  { 
          for (i=1;(i*i+1)/2<x;i+=2);
          printf("%d\n",i);
        }
}