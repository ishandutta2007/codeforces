#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int a,b;
char s[101];
Int L;
Int AddX=0,AddY=0;
Int CurX=0,CurY=0;

int main()
{
    Int i;
    Int m1,m2;

    scanf("%I64d %I64d",&a,&b);
    scanf("%s",s);

    L=strlen(s);

    for (i=0;i<L;i++)
    {
        switch(s[i])
        {
            case 'U':
            AddY++;
            break;

            case 'R':
            AddX++;
            break;

            case 'D':
            AddY--;
            break;

            case 'L':
            AddX--;
            break;
        }
    }

    if (a==0 && b==0)
    {
        printf("Yes\n");
        return 0;
    }

    for (i=0;i<L;i++)
    {
        switch(s[i])
        {
            case 'U':
            CurY++;
            break;

            case 'R':
            CurX++;
            break;

            case 'D':
            CurY--;
            break;

            case 'L':
            CurX--;
            break;
        }

        if (AddX==0 && AddY==0)
        {
            if (CurX==a && CurY==b)
            {
                printf("Yes\n");
                return 0;
            }
            continue;
        }
        if (AddX==0)
        {
            if (CurX==a)
            {
                if ( (b-CurY)%AddY==0 )
                {
                    m1=(b-CurY)/AddY;
                    if (m1>=0)
                    {
                        printf("Yes\n");
                        return 0;
                    }
                }
            }
            continue;
        }
        if (AddY==0)
        {
            if (CurY==b)
            {
                if ( (a-CurX)%AddX==0 )
                {
                    m1=(a-CurX)/AddX;
                    if (m1>=0)
                    {
                        printf("Yes\n");
                        return 0;
                    }
                }
            }
            continue;
        }

        if ( (a-CurX)%AddX==0 && (b-CurY)%AddY==0 )
        {
            m1=(a-CurX)/AddX;
            m2=(b-CurY)/AddY;

            if (m1==m2 && m1>=0)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }

    printf("No\n");

    return 0;
}