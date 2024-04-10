#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int Solve(int n)
{
    int i, s;

    for(s = 1; !(n % s); s *= 10)
        ;

    return n % s;
}

int main(void)
{
    int t, n;
    int i;
    vector<int> o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        o.clear();
        for(; n; n -= Solve(n))
            o.push_back(Solve(n));
        printf("%d\n", (int)o.size());
        for(i = 0; i < (signed)o.size(); i ++)
            printf("%d%c", o[i], " \n"[i == (signed)o.size() - 1]);
    }

    return 0;
}