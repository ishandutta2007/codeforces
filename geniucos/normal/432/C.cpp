#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,nr,Nr,i,j,p[100009],a[100009],cr[100009],ul[100009],ap[100009],A[500009],B[500009];
void swap(int i,int j)
{
    int aux=a[i];
    a[i]=a[j];
    a[j]=aux;
    p[a[i]]=i;
    p[a[j]]=j;
    A[++Nr]=j;
    B[Nr]=i;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]),p[a[i]]=i;
for(i=2;i*i<=n;i++)
    if(cr[i]==0)
    {
        for(j=i*i;j<=n;j+=i)
            cr[j]=1;
    }
for(i=2;i<=n;i++)
    if(cr[i]==0) ap[i-1]=1;
for(i=1;i<=n;i++)
{
    if(ap[i]) ul[i]=i;
    else ul[i]=ul[i-1];
}
for(i=1;i<=n;i++)
    if(p[i]!=i)
    {
        nr=p[i]-i;
        while(nr)
        {
            swap(p[i],p[i]-ul[nr]);
            nr-=ul[nr];
        }
    }
printf("%d\n",Nr);
for(i=1;i<=Nr;i++)
    printf("%d %d\n",A[i],B[i]);
return 0;
}