#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,a[100005];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n*2;i++)a[i]=i;
    if(k+1<=n)
    {
        for(int i=1;i<=k;i++)a[2*i-1]=a[2*i]+1;
        a[2*k+1]=1;
    }else
    {
        for(int i=1;i<n;i++)a[2*i-1]=a[2*i]+1;
        a[2*n-1]=1;
        swap(a[1],a[3]);
    }
    for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
    return 0;
}