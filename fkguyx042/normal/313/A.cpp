#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<cmath>
using namespace std;
int n;
int main()
{scanf("%d",&n);
  if(n>=0) printf("%d\n",n);
  else {
  	 if(abs(n)%10>abs(n)%100/10)
  	   printf("%d\n",n/10);
  	   else printf("%d\n",n/100*10-abs(n)%10);
  }
}