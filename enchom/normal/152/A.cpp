#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

Int marks[101][101];
Int subject[101];

int main()
{
    Int n,m;
    char ch;
    Int i,j;
    Int successfull=0;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>ch;
            marks[i][j]=ch-'0';
        }
    }
    for (i=0;i<=100;i++)
    subject[i]=-1;
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (marks[i][j]>subject[j])
            subject[j]=marks[i][j];
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (marks[i][j]==subject[j])
            {
                successfull++;
                break;
            }
        }
    }
    printf("%I64d\n",successfull);
    return 0;
}