#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char word1[2000001];
char word2[2000001];
Int L;

int main()
{
    Int i;
    Int intersections=0;
    Int ones1=0,ones2=0;
    Int left1,left2;

    scanf("%I64d",&L);

    scanf("%s",word1+1);
    scanf("%s",word2+1);

    for (i=1;i<=2*L;i++)
    {
        if (word1[i]=='1' && word2[i]=='1')
        {
            intersections++;
        }
        if (word1[i]=='1')
        {
            ones1++;
        }
        if (word2[i]=='1')
        {
            ones2++;
        }
    }

    left1=ones1-intersections;
    left2=ones2-intersections;

    if (intersections%2==1)
    {
        if (left1>left2)
        {
            printf("First\n");
        }
        else if (left1<left2)
        {
            if (left2-left1>2)
            {
                printf("Second\n");
            }
            else
            {
                printf("Draw\n");
            }
        }
        else
        {
            printf("First\n");
        }
    }
    else
    {
        if (left1>left2)
        {
            printf("First\n");
        }
        else if (left1<left2)
        {
            if (left2-left1>1)
            {
                printf("Second\n");
            }
            else
            {
                printf("Draw\n");
            }
        }
        else
        {
            printf("Draw\n");
        }
    }

    return 0;
}