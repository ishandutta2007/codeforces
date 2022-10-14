// Codeforces Beta Round #9
// Problem A -- Die Roll
#include <cstdio>

using namespace std;

int a, b, x, y;

int main()
{
    scanf("%d%d", &a, &b);
    x = 7 - (a < b? b: a), y = 6;
    if(!(x % 2) && !(y % 2))
        x /= 2, y /= 2;
    if(!(x % 3) && !(y % 3))
        x /= 3, y /= 3;
    printf("%d/%d\n", x, y);
    return 0;
}