#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n;
int p[100111];

int mem[102][2][53][53];
int solve(int ind, bool evenprev, int evens, int odds)
{
    if (ind > n)
        return 0;
    if (mem[ind][evenprev][evens][odds] != -1)
        return mem[ind][evenprev][evens][odds];

    int ans = n;

    if (p[ind] == 0)
    {
        if (evens > 0)
        {
            ans = min(ans, solve(ind+1, true, evens-1, odds) + (int)(!evenprev) );
        }
        if (odds > 0)
        {
            ans = min(ans, solve(ind+1, false, evens, odds-1) + (int)(evenprev));
        }
    }
    else
    {
        if (p[ind] % 2 == 0)
            ans = solve(ind+1, true, evens, odds) + (int)(!evenprev);
        else
            ans = solve(ind+1, false, evens, odds) + (int)(evenprev);
    }

    mem[ind][evenprev][evens][odds] = ans;

    return ans;
}

int main()
{
    int i,j;
    int ans = 0;
    int odds, evens;

    memset(mem,-1,sizeof(mem));

    scanf("%d",&n);

    evens = n / 2;
    odds = n - evens;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);

        if (p[i] == 0)
            continue;

        if (p[i] % 2 == 0)
            evens--;
        else
            odds--;
    }

    printf("%d\n",min(solve(1, false, evens, odds), solve(1, true, evens, odds)));

    return 0;
}