#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int digits1[201];
Int digits2[201];

bool SortEm(Int a,Int b)
{
    return (a>b);
}

int main()
{
    Int n;
    Int i;
    string k;
    bool more;
    
    scanf("%I64d",&n);
    
    cin>>k;
    
    for (i=0;i<n;i++)
    {
        digits1[i+1]=(int)( k[i]-'0' );
    }
    for (i=n;i<2*n;i++)
    {
        digits2[i-n+1]=(int)( k[i]-'0' );
    }
    
    sort(digits1+1,digits1+1+n,SortEm);
    sort(digits2+1,digits2+1+n,SortEm);
    
    if (digits1[1]==digits2[1])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else if (digits1[1]>digits2[1])
    {
        more=true;
    }
    else
    {
        more=false;
    }
    
    for (i=2;i<=n;i++)
    {
        if (more)
        {
            if (digits1[i]<=digits2[i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else
        {
            if (digits1[i]>=digits2[i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}