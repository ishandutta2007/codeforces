#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

bool seenletter[256];
char code[100001];
Int L;

int main()
{
    Int i;
    Int questions=0;
    Int letters=0;
    Int total;

    for (i=0;i<=255;i++)
    {
        seenletter[i]=false;
    }

    scanf("%s",code);
    L=strlen(code);

    for (i=0;i<L;i++)
    {
        if (code[i]=='?')
        {
            questions++;
        }
        if (code[i]>='A' && code[i]<='Z')
        {
            if (!seenletter[ code[i] ])
            {
                seenletter[ code[i] ]=true;
                letters++;
            }
        }
    }

    total=1;
    if (code[0]<'A' || code[0]>'Z')
    {
        for (i=10;i>=10-letters+1;i--)
        {
            total=total*i;
        }
    }
    else
    {
        total=9;
        for (i=9;i>=9-letters+2;i--)
        {
            total=total*i;
        }
    }

    if (code[0]=='?')
    {
        questions--;
        total=total*9;
    }

    printf("%I64d",total);
    for (i=1;i<=questions;i++)
    {
        printf("0");
    }
    printf("\n");

    return 0;
}