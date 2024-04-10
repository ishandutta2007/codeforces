#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[101];
double add[101];
int n;
int total=0;
int themax=0;
double b;

int main()
{
    int i,j;
    
    cin>>n>>b;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>themax)
        themax=a[i];
    }
    
    for (i=1;i<=n;i++)
    {
        total=total+(themax-a[i]);
        add[i]=themax-a[i];
    }
    b=b-total;
    if (b<0)
    {
        cout<<-1<<endl;
        return 0;
    }
    b=b/n;
    for (i=1;i<=n;i++)
    {
        add[i]=add[i]+b;
        printf("%4.6f\n",add[i]);
    }
    return 0;
}