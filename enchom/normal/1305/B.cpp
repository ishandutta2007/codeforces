#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n;
char s[2011];
vector<int> taken;

int main()
{
    int i,j;

    scanf("%s",s+1);
    n = strlen(s+1);

    int backptr = n;
    for (i=1;i<=n;i++)
    {
        if (i >= backptr)
            break;

        if (s[i] == '(')
        {
            while(backptr > i && s[backptr] != ')')
                backptr--;

            if (backptr <= i)
                break;

            taken.push_back(i);
            taken.push_back(backptr);

            backptr--;
        }
    }

    if (taken.empty())
    {
        printf("0\n");
        return 0;
    }

    sort(taken.begin(),taken.end());

    printf("1\n");
    printf("%d\n",taken.size());

    for (i=0;i<taken.size();i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d",taken[i]);
    }
    printf("\n");

    return 0;
}