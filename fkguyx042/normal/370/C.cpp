#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k;
int a[5001],b[5001];
inline bool cmp(int a,int b) { return a>b;}
int main()
{ scanf("%d%d",&n,&p);
 for (i=0;i<n;i++) scanf("%d",&a[i]);
   sort(a,a+n);
   for (i=0;i<n;i++)
     if (a[i]!=a[(i+n/2)%n]) k++;
   printf("%d\n",k);
   for (i=0;i<n;i++)
    printf("%d %d\n",a[i],a[(i+n/2)%n]);
}