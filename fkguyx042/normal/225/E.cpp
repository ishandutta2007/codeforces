#include<cstdio>
#include<algorithm>
#include<cstring>
const int Mo=(int)1e9+7;
using namespace std;
const int a[44]={0,2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951, 30402457 };
int n;
int power(int x,int y)
{ int sum=1;
  for(;y;y>>=1)
  {  if (y&1) sum=1ll*sum*x%Mo;
    x=1ll*x*x%Mo;
  }
  return sum;
}
int main()
{ scanf("%d",&n);
 printf("%d\n",(power(2,a[n]-1)+Mo-1)%Mo);
 }