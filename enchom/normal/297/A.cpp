#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char a[3001];
char b[3001];
Int aL,bL;
Int zerolimit;

int main()
{
    Int i,j;
    bool bad;
    Int Aones=0,Bones=0;
    Int maxaones;

    scanf("%s",a+1);
    aL=strlen(a+1);
    scanf("%s",b+1);
    bL=strlen(b+1);

    for (i=1;i<=aL;i++)
    {
        if (a[i]=='1')
        {
            Aones++;
        }
    }

    if (Aones%2==0)
    {
        maxaones=Aones;
    }
    else
    {
        maxaones=Aones+1;
    }

    for (i=1;i<=bL;i++)
    {
        if (b[i]=='1')
        {
            Bones++;
        }
    }

    if (Bones<=maxaones)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}