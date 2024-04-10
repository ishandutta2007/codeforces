#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char str[101];
int L;
bool small=false,large=false,digit=false;

int main()
{
    int i;

    scanf("%s",str+1);
    L=strlen(str+1);

    if (L<5)
    {
        printf("Too weak\n");
        return 0;
    }

    for (i=1;i<=L;i++)
    {
        if (str[i]>='A' && str[i]<='Z')
        large=true;
        if (str[i]>='a' && str[i]<='z')
        small=true;
        if (str[i]>='0' && str[i]<='9')
        digit=true;
    }

    if (large && small && digit)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Too weak\n");
    }

    return 0;
}