#include<cstdio>
using namespace std;
long long n,m;
long long Do()
{ if (n%m==0) return m*((n/m)*(n/m-1)/2);
  return (n%m)*(n/m+1)*(n/m)/2+(m-n%m)*(n/m)*(n/m-1)/2;}
int main()
{ scanf("%I64d%I64d",&n,&m);
 printf("%I64d %I64d",Do(),(n-m+1)*(n-m)/2);
}