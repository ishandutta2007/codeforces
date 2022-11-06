#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
typedef pair <Pii, int> PPi;
#define x first
#define y second
#define mp make_pair
#define N 100000 + 5

int n, l, x, y, t, p, q, A[N];
bool getx, gety, getsum, getcha;

int main()
{
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    
    int head = 1;
    for (int i = 1; i <= n && !getx; i ++)
    {
        while (A[i] - A[head] > x)
            head ++;
        if (A[i] - A[head] == x)
            getx = 1;
    }
    
    head = 1;
    for (int i = 1; i <= n && !gety; i ++)
    {
        while (A[i] - A[head] > y)
            head ++;
        if (A[i] - A[head] == y)
            gety = 1;
    }
    
    head = 1;
    for (int i = 1; i <= n && !getsum; i ++)
    {
        while (A[i] - A[head] > x + y)
            head ++;
        if (A[i] - A[head] == x + y)
        {
            getsum = 1;
            t = head;
        }
    }
    
    head = 1;
    for (int i = 1; i <= n && !getcha; i ++)
    {
        while (A[i] - A[head] > y - x)
            head ++;
        if (A[i] - A[head] == y - x && (A[head] > x || A[i] + x < l))
        {
            getcha = 1;
            p = head, q = i;
        }
    }
    
    if (!getx && !gety && !getsum && !getcha)
    {
        printf("2\n%d %d\n", x, y);
    }
    else if (getx && gety)
    {
        puts("0");
    }
    else if (getsum)
    {
        printf("1\n%d\n", A[t] + x);
    }
    else if (getcha)
    {
        if (A[p] > x)
            printf("1\n%d\n", A[p] - x);
        else printf("1\n%d\n", A[q] + x);
    }
    else if (!getx)
    {
        printf("1\n%d\n", x);
    }
    else if (!gety)
    {
        printf("1\n%d\n", y);
    }
    return 0;
}