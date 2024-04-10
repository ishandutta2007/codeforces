#include <iostream>
#include <stdio.h>
using namespace std;

int n, d;

int father[2011];
int sz[2011];
int Find(int ver)
{
    if (father[ver] == 0)
        return ver;
    else
    {
        father[ver] = Find(father[ver]);
        return father[ver];
    }
}

int thisSize[1011];

void Union(int r1, int r2)
{
    thisSize[ sz[r1] ]--;
    thisSize[ sz[r2] ]--;
    sz[r1] += sz[r2];
    father[r2] = r1;

    thisSize[ sz[r1] ]++;
}

int frees = 1;

int compute()
{
    int i, j;
    int freeLeft = frees;
    int ans = 0;

    for (i=n;i>=1;i--)
    {
        for (j=1;j<=thisSize[i];j++)
        {
            if (freeLeft == 0)
                break;

            freeLeft--;
            ans += i;
        }

        if (freeLeft == 0)
            break;
    }

    return ans;
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &d);

    for (i=1;i<=n;i++)
    {
        sz[i] = 1;
        father[i] = 0;
    }
    thisSize[1] = n;

    for (i=1;i<=d;i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        int r1 = Find(a);
        int r2 = Find(b);

        if (r1 == r2)
        {
            frees++;
        }
        else
        {
            Union(r1, r2);
        }

        printf("%d\n", compute() - 1);
    }
}