#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector<char> lefty;
vector<char> righty;
char inp[1001];
int L;

int main()
{
    int i;

    scanf("%s",inp+1);
    L=strlen(inp+1);

    for (i=1;i<=L;i++)
    {
        if (inp[i]=='|')
        {
            i++;
            break;
        }

        lefty.push_back(inp[i]);
    }

    for (i;i<=L;i++)
    {
        righty.push_back(inp[i]);
    }

    scanf("%s",inp+1);
    L=strlen(inp+1);

    for (i=1;i<=L;i++)
    {
        if (lefty.size()<=righty.size())
        {
            lefty.push_back(inp[i]);
        }
        else
        {
            righty.push_back(inp[i]);
        }
    }

    if (lefty.size()==righty.size())
    {
        for (i=0;i<lefty.size();i++)
        {
            printf("%c",lefty[i]);
        }
        printf("|");
        for (i=0;i<righty.size();i++)
        {
            printf("%c",righty[i]);
        }

        printf("\n");
    }
    else
    {
        printf("Impossible\n");
    }

    return 0;
}