#include<iostream>
#include<fstream>
using namespace std;
int n,a[234567],i,cnt,s,s1;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    for(i=0;i<n;i++)
    {
        s1+=a[i];
        if(s1>=(s+1)/2)break;
    }
    printf("%d",i+1);
    return 0;
}