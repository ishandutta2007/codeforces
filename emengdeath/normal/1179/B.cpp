#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
using namespace std;
const int N = 1e5 + 1;
int n, m;
deque<int> f, g;
void work(int x , int y, int n , int m) {
    if (n <= 3 && m <= 3 && !(n == 3 && m == 3)) {
        if (n == 1) {
            if (m == 1) {
                printf("%d %d\n", x, y);
                return;
            }
            else
                if (m == 2) {
                    printf("%d %d\n%d %d\n", x ,y, x, y + 1);
                    return;
                }
                else {
                    printf("%d %d\n%d %d\n%d %d\n", x, y, x, y + 2, x, y + 1);
                    return;
                }
        } else
            if (n == 2) {
                if (m == 1) {
                    printf("%d %d\n%d %d\n", x, y, x + 1, y);
                    return;
                }
                else
                    if (m == 2) {
                        printf("%d %d\n%d %d\n%d %d\n%d %d\n", x, y, x + 1, y + 1, x + 1, y, x, y + 1);
                        return;
                    }
            } else
            {
                if (m == 1) {
                    printf("%d %d\n%d %d\n%d %d\n", x, y, x + 2, y, x + 1, y);
                    return;
                }
            }
    }
    if (n > m) {
        for (int i = 0; i < m ; i ++) {
            printf("%d %d\n", x, y + i);
            printf("%d %d\n", x + n - 1, y + m - i - 1);
        }
        work(x + 1, y, n - 2, m);
    } else {
        for (int i = 0; i < n ; i ++) {
            printf("%d %d\n", x + i, y);
            printf("%d %d\n", x + n - i - 1, y + m - 1);
        }
        work(x, y + 1, n, m - 2);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    if (n == 1) {
        for (int i = 1; i + i <= m + 1; i ++)
        {
            printf("%d %d\n", 1, i);
            if (i != m - i + 1)
                printf("%d %d\n", 1, m - i  + 1);
        }
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i + i <= n + 1; i ++)
        {
            printf("%d %d\n", i, 1);
            if (i != n - i + 1)
                printf("%d %d\n", n - i  + 1, 1);
        }
        return 0;
    }
    work(1, 1, n, m);
    return 0;
}