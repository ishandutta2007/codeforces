#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[4];
int main()
{scanf("%d",&n);
  for (;n--;)
  {  scanf("%s",&c);
    if (c[1]=='+') p++; else p--;
}
printf("%d\n",p);
}