#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char a[100001];
char b[100001];

Int wrongplace4=0,wrongplace7=0;
Int L;

int main()
{
    Int i;

    scanf("%s",a);
    scanf("%s",b);
    L=strlen(a);

    for (i=0;i<L;i++)
    {
        if (a[i]!=b[i])
        {
            if (a[i]=='4')
            wrongplace4++;
            else
            wrongplace7++;
        }
    }

    if (wrongplace4>wrongplace7)
    {
        printf("%I64d\n",wrongplace7+wrongplace4-wrongplace7);
    }
    else
    {
        printf("%I64d\n",wrongplace4+wrongplace7-wrongplace4);
    }

    return 0;
}