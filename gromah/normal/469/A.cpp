#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000 + 5

int n, cnt;
bool Vis[N];

int main()
{
    scanf("%d", &n);
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int u;
        scanf("%d", &u);
        if (!Vis[u]) cnt ++;
        Vis[u] = 1;
    }
    scanf("%d", &t);
    while (t --)
    {
        int u;
        scanf("%d", &u);
        if (!Vis[u]) cnt ++;
        Vis[u] = 1;
    }
    if (cnt == n) puts("I become the guy.");
        else puts("Oh, my keyboard!");
    return 0;
}