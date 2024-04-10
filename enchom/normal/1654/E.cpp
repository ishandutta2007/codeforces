#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
using namespace std;
typedef long long llong;

const int K = 50;

int n;
int a[200111];

int ans;

unordered_map<int, int> small;

void solveSmall()
{
    int i, j;

    for (int step = -K; step <= K; step++)
    {
        small.clear();
        for (i=0;i<n;i++)
        {
            int firstNum = a[i] - i * step;
            auto it = small.find(firstNum);

            if (it == small.end())
                small.insert(make_pair(firstNum, 1));
            else
                (*it).second++;
        }

        for (auto it = small.begin(); it != small.end(); it++)
        {
            ans = min(ans, n - (*it).second);
        }
    }

    return;
}

int stepCnts[300111];
bool skip[300111];
int stepsMem[300111];
const int OFFSET = 100001;

void solveBig()
{
    int i, j;
    int sz = 1;

    while( (sz - 1) * K <= 100000 )
        sz++;

    for (i=0;i<n;i++)
    {
        for (j=i+1;j<=i+sz-1;j++)
        {
            if (j >= n)
                continue;

            int top = a[j] - a[i];
            int bot = j - i;

            int step = top / bot;
            if (step * bot != top)
            {
                skip[j] = true;
                continue;
            }
            skip[j] = false;

            stepCnts[step + OFFSET]++;
            stepsMem[j] = step;

            ans = min(ans, n - 1 - stepCnts[step + OFFSET]);
        }

        for (j=i+1;j<=i+sz-1;j++)
        {
            if (j >= n)
                continue;
            if (skip[j])
                continue;

            stepCnts[ stepsMem[j] + OFFSET ]--;
        }
    }
}

int main()
{
    int i, j;

    scanf("%d", &n);
    ans = n - 1;

    for (i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    solveSmall();
    solveBig();

    printf("%d\n", ans);
}