#include<iostream>
#include<fstream>
using namespace std;
int p[12345],a[12345];
int i,n;
void msort(int *a,int *b)
{
    if(a>b-2)return;
    int n=b-a,t=0,i;
    msort(a,a+n/2);
    msort(a+n/2,b);
    int *x=a,*y=a+n/2;
    while(t<n)
    {
        if((*x<=*y&&x<a+n/2)||y>=b)
        {
            p[t++]=*x;
            x++;
        }
        else
        {
            p[t++]=*y;
            y++;
        }
    }
    for(i=0;i<n;i++)
    {
        *(a+i)=p[i];
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    msort(a,a+n);
    printf("%d",a[(n-1)/2]);
    return 0;
}