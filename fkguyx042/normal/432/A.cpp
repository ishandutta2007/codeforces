#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
 { scanf("%d%d",&n,&k);
   for(i=1;i<=n;i++)
    { scanf("%d",&p);
      if (5-p>=k) m++;
}
printf("%d\n",m/3);
}