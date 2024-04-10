#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <vector>
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

string getFirstHalf()
{
    string ans;
    int halfN = (n + 1) / 2;
    int i,j;

    printf("? 1 %d\n",halfN);
    fflush(stdout);

    for (i=1;i<=halfN;i++)
    {
        for (j=i;j<=halfN;j++)
        {
            myset.insert(getString());
        }
    }

    if (halfN == 1)
    {
        return (*myset.begin());
    }

    printf("? 2 %d\n",halfN);
    fflush(stdout);

    for (i=1;i<=halfN-1;i++)
    {
        for (j=i;j<=halfN-1;j++)
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
    ans.push_back(perlen[1][0]);

    for (i=2;i<=halfN;i++)
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
                ans.push_back(j + 'a');
                break;
            }
        }
    }

    return ans;
}

vector<string> all;

int seen[27];

int main()
{
    int i,j,in,ja;

    scanf("%d",&n);

    if (n == 1)
    {
        printf("? 1 1\n");
        fflush(stdout);

        scanf("%s",inp);

        printf("! %c\n",inp[0]);
        fflush(stdout);

        return 0;
    }

    string half = getFirstHalf();
    int rem = n - half.size();

    printf("? 1 %d\n",n);
    fflush(stdout);

    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            all.push_back(getString());
        }
    }

    string backBuild;

    for (i=1;i<=rem;i++)
    {
        memset(seen,0,sizeof(seen));

        for (j=0;j<all.size();j++)
        {
            if (all[j].length() == i+1)
            {
                for (in=0;in<all[j].length();in++)
                {
                    seen[ all[j][in] - 'a' ]++;
                }
            }
        }

        for (j=0;j<i-1;j++)
        {
            seen[ half[j] - 'a' ] -= (j+1);
            seen[ backBuild[j] - 'a' ] -= (j+1);
        }

        seen[ half[i-1] - 'a' ] -= i;

        char candidate = half[i-1];
        for (j=0;j<=26;j++)
        {
            if (seen[j] % (i+1) != 0)
            {
                candidate = j + 'a';
                break;
            }
        }

        backBuild.push_back(candidate);
    }

    reverse(backBuild.begin(), backBuild.end());

    string res = half + backBuild;

    printf("! %s\n",res.c_str());
    fflush(stdout);

    return 0;
}