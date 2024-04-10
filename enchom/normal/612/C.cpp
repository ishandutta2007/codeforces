#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[1000111];
int n;

char stk[1000111];
int L=0;

bool Opening(char ch)
{
    if (ch=='(' || ch=='<' || ch=='{' || ch=='[')
    return true;
    else
    return false;
}

bool Matching(char a,char b)
{
    if (a=='{' && b=='}')
    return true;
    else if (a=='[' && b==']')
    return true;
    else if (a=='<' && b=='>')
    return true;
    else if (a=='(' && b==')')
    return true;

    return false;
}

int main()
{
    int i;
    int ans=0;

    scanf("%s",s+1);
    n=strlen(s+1);

    for (i=1;i<=n;i++)
    {
        if ( Opening(s[i]) )
        {
            L++;
            stk[L]=s[i];
        }
        else
        {
            if (L==0)
            {
                printf("Impossible\n");
                return 0;
            }

            if (Matching(stk[L],s[i]))
            {
                L--;
            }
            else
            {
                ans++;
                L--;
            }
        }
    }

    if (L>0)
    {
        printf("Impossible\n");
        return 0;
    }

    printf("%d\n",ans);

    return 0;
}