#include<stdio.h>
#include<algorithm>
using namespace std; 
main()
{

    
    int n,l;
    float Max=0;
    scanf("%d %d",&n,&l);
    int a[1000];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,a+n);
    Max=(a[0]-0)*2;
    Max=max((l-a[n-1])*2,(int)Max);
    for(int i=1;i<n;i++)
    {
        Max=max((int)Max,a[i]-a[i-1]);
    }
    printf("%.10f",Max/2);
    return 0;
}