#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5
int t, n, r;
bool F[N];

void begin()
{
    scanf("%d%d", &t, &n);
}

void work()
{
    for (int i = 1; i <= n; i ++)
    {
        int q;
        scanf("%d", &q);
        if (F[q % t])
        {
            printf("%d\n", i);
            return ;
        }
        F[q % t] = 1;
    }
    printf("-1\n");
}

void end()
{
    
}

int main()
{
    begin();
    work();
    end();
    return 0;
}