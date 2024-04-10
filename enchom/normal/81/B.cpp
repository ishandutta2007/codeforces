#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

struct item
{
    Int type; ///1-nubmer , 2-coma , 3-...
    char num[260];
    Int nL;
};

item items[1001];
Int iL=0;

int main()
{
    char ch;
    Int dots=0;
    Int lastone;
    bool number=false;
    Int i,j;
    
    while(1)
    {
        scanf("%c",&ch);
        
        if (ch==10)
        break;
        
        if (ch==',')
        {
            iL++;
            items[iL].type=2;
            number=false;
        }
        else if (ch=='.')
        {
            dots++;
            number=false;
            if (dots==3)
            {
                iL++;
                items[iL].type=3;
                dots=0;
            }
        }
        else if (ch>='0' && ch<='9')
        {
            if (!number)
            {
                iL++;
                items[iL].type=1;
                items[iL].nL=1;
                items[iL].num[1]=ch;
                number=true;
            }
            else
            {
                items[iL].nL++;
                items[iL].num[ items[iL].nL ]=ch;
            }
        }
        else
        {
            number=false;
        }
    }
    
    lastone=-1;
    for (i=1;i<=iL;i++)
    {
        if (items[i].type==1)
        {
            if (lastone==1 || lastone==2)
            {
                printf(" ");
            }
            for (j=1;j<=items[i].nL;j++)
            {
                printf("%c",items[i].num[j]);
            }
            lastone=1;
        }
        else if (items[i].type==2)
        {
            if (lastone==2)
            {
                printf(" ");
            }
            printf(",");
            lastone=2;
        }
        else if (items[i].type==3)
        {
            if (i!=1)
            printf(" ...");
            else
            printf("...");
            
            lastone=3;
        }
    }
    printf("\n");
    return 0;
}