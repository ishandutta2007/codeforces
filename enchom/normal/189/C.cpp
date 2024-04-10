#include <iostream>
#include <stdio.h>
using namespace std;

int way1[200001],way2[200001];
int where[200001];

int main()
{
    int n;
    int i;
    int mustpush=0;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    scanf("%d",&way1[i]);
    for (i=1;i<=n;i++)
    scanf("%d",&way2[i]);
    
    for (i=1;i<=n;i++)
    {
        where[way2[i]]=i;
    }
    for (i=1;i<=n;i++)
    {
        if (where[way1[i]]-i<mustpush || where[way1[i]]<i)
        {
            cout<<n-i+1<<endl;
            return 0;
        }
        else
        {
            if (where[way1[i]]-i>mustpush)
            mustpush=where[way1[i]]-i;
        }
    }
    cout<<0<<endl;
    return 0;
}