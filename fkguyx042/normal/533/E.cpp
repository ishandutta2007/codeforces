#include<stdio.h>
int n,cnt;
char a[100010],b[100010];
int main()
{
    int i,p1,p2,c=1;
    scanf("%d",&n);
    scanf("%s",a); scanf("%s",b);
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i]){p1=i; break;}
    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]!=b[i]){p2=i; break;}
    }
    for(i=p1+1;i<=p2;i++)
    {
        if(c && b[i]!=a[i-1])
        {
            c=0;
        }
        if(c==0 && a[i]!=b[i]) break;
    }
    if(i==p2+1) cnt++;
    c=1;
    for(i=p1+1;i<=p2;i++)
    {
        if(c && a[i]!=b[i-1])
        {
            c=0;
        }
        if(c==0 && a[i]!=b[i]) break;
    }
    if(i==p2+1) cnt++;
    printf("%d",cnt);
    return 0;
}