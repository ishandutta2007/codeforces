#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

struct logs
{
    char name1[31],name2[31];
    Int name1L,name2L,t;
};
struct friendies
{
    char name1[31],name2[31];
    Int name1L,name2L;
};

logs log[10001];
friendies friends[10001];
Int fL=0;

bool Same(char arr1[],Int L1,char arr2[],Int L2)
{
    if (L1!=L2)
    return false;
    
    Int i;
    
    for (i=1;i<=L1;i++)
    {
        if (arr1[i]!=arr2[i])
        return false;
    }
    return true;
}

int main()
{
    string a;
    string b;
    Int i,j,n,d;
    Int found;
    bool addfriend;
    
    scanf("%I64d %I64d",&n,&d);
    
    for (i=1;i<=n;i++)
    {
        cin>>a;
        cin>>b;
        scanf("%I64d",&log[i].t);
        
        log[i].name1L=a.length();
        for (j=0;j<a.length();j++)
        {
            log[i].name1[j+1]=a[j];
        }
        log[i].name2L=b.length();
        for (j=0;j<b.length();j++)
        {
            log[i].name2[j+1]=b[j];
        }
        found=-1;
        
        for (j=i-1;j>=1;j--)
        {
            if ( Same( log[i].name1,log[i].name1L,log[j].name2,log[j].name2L ) )
            {
                if ( Same( log[i].name2,log[i].name2L,log[j].name1,log[j].name1L ) )
                {
                    if (log[i].t-log[j].t>0 && log[i].t-log[j].t<=d)
                    {
                        found=j;
                        break;
                    }
                }
            }
        }
        if (found!=-1)
        {
                addfriend=true;
                for (j=1;j<=fL;j++)
                {
                    if ( Same( log[i].name1,log[i].name1L,friends[j].name1,friends[j].name1L ) && Same( log[found].name1,log[found].name1L,friends[j].name2,friends[j].name2L ) )
                    {
                        addfriend=false;
                        break;
                    }
                    else if ( Same( log[i].name1,log[i].name1L,friends[j].name2,friends[j].name2L ) && Same( log[found].name1,log[found].name1L,friends[j].name1,friends[j].name1L ) )
                    {
                        addfriend=false;
                        break;
                    }
                }
                if (addfriend)
                {
                    fL++;
                    friends[fL].name1L=log[i].name1L;
                    for (j=1;j<=friends[fL].name1L;j++)
                    {
                        friends[fL].name1[j]=log[i].name1[j];
                    }
                     friends[fL].name2L=log[found].name1L;
                    for (j=1;j<=friends[fL].name2L;j++)
                    {
                        friends[fL].name2[j]=log[found].name1[j];
                    }
                }
        }
    }
    printf("%I64d\n",fL);
    for (i=1;i<=fL;i++)
    {
        for (j=1;j<=friends[i].name1L;j++)
        {
            printf("%c",friends[i].name1[j]);
        }
        printf(" ");
        for (j=1;j<=friends[i].name2L;j++)
        {
            printf("%c",friends[i].name2[j]);
        }
        printf("\n");
    }
    return 0;
}