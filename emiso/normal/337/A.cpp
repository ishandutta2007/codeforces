#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,i,a[55],ms=-1;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
                    scanf("%d",&a[i]);
    }
    sort(a,a+m);
    for(i=n-1;i<m;i++)
    {
                    if(ms == -1 || ms > a[i]-a[i+1-n]) ms = a[i] - a[i+1-n];
    }
    printf("%d\n",ms);
    return 0;
}