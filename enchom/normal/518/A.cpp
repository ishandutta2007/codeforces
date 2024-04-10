#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[111];
char t[111];
int n;

char ans[111];

int main()
{
    int i;
    bool smaller=true;

    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);

    for (i=1;i<=n;i++)
    {
        ans[i]=s[i];
    }

    ans[n]=ans[n]+1;
    for (i=n;i>=2;i--)
    {
        if (ans[i]>'z')
        {
            ans[i]='a';
            ans[i-1]++;
        }
    }

    smaller=false;
    for (i=1;i<=n;i++)
    {
        if (ans[i]<t[i])
        {
            smaller=true;
            break;
        }
        else if (ans[i]>t[i])
        {
            break;
        }
    }

    if (smaller)
    {
        for (i=1;i<=n;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No such string\n");
    }

    return 0;
}