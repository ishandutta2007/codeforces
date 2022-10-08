#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[500001];
char t[500001];
int n,L;

int hasLetter[1001];
bool done[500001];

char OC(char ch)
{
    if (ch>='a' && ch<='z')
    return ch-'a'+'A';
    else
    return ch-'A'+'a';
}

int main()
{
    int i;
    int YAY=0,WHOOPS=0;

    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    L=strlen(t+1);

    for (i=1;i<=L;i++)
    {
        hasLetter[ t[i] ]++;
    }

    for (i=1;i<=n;i++)
    {
        if ( hasLetter[ s[i] ]>0 )
        {
            YAY++;
            hasLetter[ s[i] ]--;
            done[i]=true;
        }
    }

    for (i=1;i<=n;i++)
    {
        if (!done[i])
        {
            if (hasLetter[ OC(s[i]) ])
            {
                WHOOPS++;
                hasLetter[ OC(s[i]) ]--;
            }
        }
    }

    printf("%d %d\n",YAY,WHOOPS);

    return 0;
}