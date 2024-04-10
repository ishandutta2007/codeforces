#include <iostream>
#include <stdio.h>
using namespace std;

int a[100001],b[100001];
int S[100001];

int main()
{
    int n,m,c;
    int i,j;
    int sum;
    
    scanf("%d %d %d",&n,&m,&c);
    
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
    scanf("%d",&b[i]);
    
    S[1]=b[1];
    for (i=2;i<=m;i++)
    S[i]=S[i-1]+b[i];
    
    for (i=1;i<=n;i++)
    {
        if (i>=m)
        sum=S[m];
        else
        sum=S[i];
        
        if (n-i<m-1)
        sum=sum-S[(m-1)-(n-i)];
        
        a[i]=a[i]+sum;
        a[i]=a[i]%c;
    }
    for (i=1;i<=n;i++)
    {
        cout<<a[i];
        if (i!=n)
        cout<<" ";
        else
        cout<<endl;
    }
    return 0;
}