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
#define N 5000 + 5

int n;
Pii P[N];

inline bool cmp(Pii u, Pii v)
{
    return (u.x < v.x || (u.x == v.x && u.y < v.y));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        P[i] = mp(u, v);
    }
    sort(P + 1, P + n + 1, cmp);
    
    bool ok = 1;
    int data = 0;
    for (int i = 1; i <= n && ok; i ++)
    {
        if (data <= P[i].y)
            data = P[i].y;
        else if (data > P[i].y && data <= P[i].x)
            data = P[i].x;
        else ok = 0;
    }
    
    printf("%d\n", data);
    return 0;
}