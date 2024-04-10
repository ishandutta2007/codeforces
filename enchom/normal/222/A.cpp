#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int seq[100001];

int main()
{
    Int k,n;
    Int i;
    Int firstdif;
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    scanf("%I64d",&seq[i]);
    
    for (i=n-1;i>=k;i--)
    {
        if (seq[i]!=seq[i+1])
        {
            printf("-1\n");
            return 0;
        }
    }
    firstdif=0;
    for (i=k;i>=1;i--)
    {
        if (seq[i]!=seq[k])
        {
            firstdif=i;
            break;
        }
    }
    cout<<firstdif<<endl;
    return 0;
}