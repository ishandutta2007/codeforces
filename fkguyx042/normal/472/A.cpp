#include<cstdio>
using namespace std;
int n;
int main()
{scanf("%d",&n);
  if (n&1)
  printf("%d %d\n",n-9,9);
  else  printf("%d %d\n",n-4,4);
      	
}