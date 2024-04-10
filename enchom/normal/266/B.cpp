#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char thequeue[51];

int main()
{
    Int n,t;
    Int i;
    Int j;
    
    scanf("%I64d %I64d",&n,&t);
    
    for (i=1;i<=n;i++)
    {
        cin>>thequeue[i];
    }
    
    for (i=1;i<=t;i++)
    {
        j=n;
        
        while(j>1)
        {
            if (thequeue[j]=='G' && thequeue[j-1]=='B')
            {
                thequeue[j]='B';
                thequeue[j-1]='G';
                j=j-2;
            }
            else
            j--;
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%c",thequeue[i]);
    }
    printf("\n");
    return 0;
}