#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

vector<char> ourstack;

bool Allowed(char ch)
{
    if (ch>='0' && ch<='9')
    return true;
    if (ch>='a' && ch<='z')
    return true;
    if (ch>='A' && ch<='Z')
    return true;
    if (ch=='.' || ch==',' || ch=='?' || ch=='"' || ch=='!')
    return true;

    return false;
}

int main()
{
    char ch;
    Int i;
    bool openedbracket=false;

    while(scanf("%c",&ch)==1)
    {
        if (openedbracket)
        {
            if (ch=='"')
            {
                printf("<");
                for (i=0;i<ourstack.size();i++)
                {
                    printf("%c",ourstack[i]);
                }
                printf(">\n");
                ourstack.clear();
                openedbracket=false;
                continue;
            }
            ourstack.push_back(ch);
            continue;
        }
        if (Allowed(ch))
        {
            if (ch=='"')
            {
                openedbracket=!openedbracket;
            }
            else
            {
                ourstack.push_back(ch);
            }
        }
        else
        {
            if (ourstack.size()>0)
            {
                printf("<");
                for (i=0;i<ourstack.size();i++)
                {
                    printf("%c",ourstack[i]);
                }
                printf(">\n");

                ourstack.clear();
            }
        }
    }

    if (ourstack.size()>0)
    {
        printf("<");
        for (i=0;i<ourstack.size();i++)
        {
            printf("%c",ourstack[i]);
        }
        printf(">\n");

        ourstack.clear();
    }

    return 0;
}