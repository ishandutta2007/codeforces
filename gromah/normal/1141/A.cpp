#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;

int Get(int x, int y)
{
    if (y % x) return -1;
    y /= x;
    int res = 0;
    for (; y > 1 && (y % 2 == 0 || y % 3 == 0); res ++)
        y /= (y % 2 == 0 ? 2 : 3);
    return y == 1 ? res : -1;
}

int main()
{
    scanf("%d%d", &a, &b);
    printf("%d\n", Get(a, b));
    return 0;
}