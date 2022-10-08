#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n;
llong nums[300111];

int mem[2][2][111][111];

int solve(int curPar, int aliceMoves, int oddsLeft, int evensLeft)
{
    if (mem[curPar][aliceMoves][oddsLeft][evensLeft] != -1)
        return mem[curPar][aliceMoves][oddsLeft][evensLeft];
    if (oddsLeft == 0 && evensLeft == 0)
        return curPar ^ 1;

    int r1 = -1;
    if (oddsLeft > 0)
        r1 = solve((curPar + aliceMoves) % 2, aliceMoves ^ 1, oddsLeft - 1, evensLeft);
    int r2 = -1;
    if (evensLeft > 0)
        r2 = solve(curPar, aliceMoves ^ 1, oddsLeft, evensLeft - 1);

    int ans;
    if (r1 == -1)
        ans = r2;
    else if (r2 == -1)
        ans = r1;
    else if (aliceMoves)
        ans = max(r1, r2);
    else
        ans = min(r1, r2);

    mem[curPar][aliceMoves][oddsLeft][evensLeft] = ans;

    return ans;
}


int main()
{
    int test;
    int i, j;

    memset(mem, -1, sizeof(mem));

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        int odds = 0;
        int evens = 0;
        for (i=1;i<=n;i++)
        {
            scanf("%lld", &nums[i]);

            if (nums[i] % 2 == 0)
                evens++;
            else
                odds++;
        }

        if (solve(0, 1, odds, evens))
            printf("Alice\n");
        else
            printf("Bob\n");
    }

    return 0;
}