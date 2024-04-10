#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k,ans;
int main()
{  scanf("%d",&n);
  n++;
   for (i=1;i<n;i++) scanf("%d",&p),k+=p;
     for (i=1;i<=5;i++)
       if ((k+i)%n!=1) ans++;
    printf("%d\n",ans);
}