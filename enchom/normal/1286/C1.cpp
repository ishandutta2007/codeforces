#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

int n;

multiset<string> myset;
multiset<string>::iterator myit;


char inp[100111];
int L;

string getString()
{
    string s;
    scanf("%s",inp);
    L = strlen(inp);

    int i;

    for (i=0;i<L;i++)
    {
        s.push_back(inp[i]);
    }

    sort(s.begin(), s.end());

    return s;
}

string perlen[111];

int cnts[27];
char ans[111];

int main()
{
    int i,j;

    scanf("%d",&n);

    printf("? 1 %d\n",n);
    fflush(stdout);

    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            myset.insert(getString());
        }
    }

    if (n == 1)
    {
        printf("! %c\n",(*myset.begin())[0]);
        return 0;
    }

    printf("? 2 %d\n",n);
    fflush(stdout);

    for (i=1;i<=n-1;i++)
    {
        for (j=i;j<=n-1;j++)
        {
            string s = getString();

            myset.erase(myset.find(s));
        }
    }

    for (myit=myset.begin();myit!=myset.end();myit++)
    {
        perlen[ (*myit).length() ] = (*myit);
    }

    cnts[ perlen[1][0] - 'a' ]++;
    ans[1] = perlen[1][0];

    for (i=2;i<=n;i++)
    {
        for (j=0;j<=26;j++)
        {
            cnts[j] = 0;
        }

        for (j=0;j<perlen[i].length();j++)
        {
            cnts[ perlen[i][j] - 'a' ]++;
        }
        for (j=0;j<perlen[i-1].length();j++)
        {
            cnts[ perlen[i-1][j] - 'a' ]--;
        }

        for (j=0;j<=26;j++)
        {
            if (cnts[j] > 0)
            {
                ans[i] = j + 'a';
                break;
            }
        }
    }

    ans[n+1] = 0;

    printf("! %s\n",ans+1);
    fflush(stdout);

    return 0;
}