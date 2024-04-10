#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

int t;
int n;
pair<int, int> degrees[200111];
int color[200111];
vector<int> colorList[200111];

int ask(int ver)
{
    printf("? %d\n", ver);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            colorList[i].clear();
            color[i] = -1;
            degrees[i].second = i;
            scanf("%d", &degrees[i].first);
        }

        sort(degrees+1, degrees+1+n);
        reverse(degrees+1, degrees+1+n);

        int colorId = 0;
        for (i=1;i<=n;i++)
        {
            int ver = degrees[i].second;
            int deg = degrees[i].first;

            if (color[ver] == -1)
            {
                colorId++;

                color[ver] = colorId;
                colorList[colorId].push_back(ver);
                int transferCol = -1;
                for (j=1;j<=deg;j++)
                {
                    int nver = ask(ver);

                    if (color[nver] == -1)
                    {
                        color[nver] = colorId;
                        colorList[colorId].push_back(nver);
                    }
                    else
                    {
                        transferCol = color[nver];
                        break;
                    }
                }

                if (transferCol != -1)
                {
                    for (j=0;j<colorList[colorId].size();j++)
                    {
                        int v = colorList[colorId][j];

                        color[v] = transferCol;
                        colorList[transferCol].push_back(v);
                    }
                    colorList[colorId].clear();
                }
            }
        }

        printf("!");
        for (i=1;i<=n;i++)
        {
            printf(" %d", color[i]);
        }
        printf("\n");
        fflush(stdout);
    }

    return 0;
}