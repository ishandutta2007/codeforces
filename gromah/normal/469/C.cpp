#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    if (n < 4)
        puts("NO");
    else
    {
        puts("YES");
        if (n == 4)
        {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("4 * 6 = 24\n");
        }
        else if (n == 5)
        {
            printf("5 + 4 = 9\n");
            printf("9 * 3 = 27\n");
            printf("27 - 2 = 25\n");
            printf("25 - 1 = 24\n");
        }
        else if (n == 6)
        {
            printf("5 * 6 = 30\n");
            printf("4 + 3 = 7\n");
            printf("7 + 1 = 8\n");
            printf("8 - 2 = 6\n");
            printf("30 - 6 = 24\n");
        }
        else if (n == 7)
        {
            printf("7 * 6 = 42\n");
            printf("5 * 4 = 20\n");
            printf("3 + 1 = 4\n");
            printf("42 - 20 = 22\n");
            printf("22 + 4 = 26\n");
            printf("26 - 2 = 24\n");
        }
        else
        {
            printf("8 + 5 = 13\n");
            printf("6 + 7 = 13\n");
            printf("13 - 13 = 0\n");
            for (int i = 9; i <= n; i ++)
                printf("0 * %d = 0\n", i);
            printf("0 + 1 = 1\n");
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("4 * 6 = 24\n");
        }
    }
    return 0;
}