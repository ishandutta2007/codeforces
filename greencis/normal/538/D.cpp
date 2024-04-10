#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,u[129][129]; /// plus 60
char s[99][99];
char ans[199][199];

void fail() {
    printf("NO");
    exit(0);
}

#define upd(dx, dy, val) u[(dy) + 60][(dx) + 60] = (val);

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%s",s[i]);

    for (int i = 0; i < 129; ++i)
        for (int j = 0; j < 129; ++j)
            u[i][j] = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'o')
                for (int y = 0; y < n; ++y)
                    for (int x = 0; x < n; ++x)
                        if (s[y][x] == '.')
                            upd(x-j, y-i, 0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'o') {
                for (int y = 0; y < 129; ++y)
                for (int x = 0; x < 129; ++x) {
                    if (!u[y][x]) continue;
                    int dx = x - 60;
                    int dy = y - 60;
                    if (j + dx < 0 || j + dx >= n || i + dy < 0 || i + dy >= n) continue;
                    if (s[i + dy][j + dx] == 'x')
                        s[i + dy][j + dx] = '.';
                }
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'x') fail();

    for (int i = 0; i < n+n-1; ++i)
        for (int j = 0; j < n+n-1; ++j)
            ans[i][j] = '.';

    for (int y = 0; y < 129; ++y)
    for (int x = 0; x < 129; ++x) {
        if (!u[y][x]) continue;
        int dx = x - 60;
        int dy = y - 60;
        if (n-1 + dx < 0 || n-1 + dx >= n+n-1 || n-1 + dy < 0 || n-1 + dy >= n+n-1) continue;
        ans[n-1 + dy][n-1 + dx] = 'x';
    }
    ans[n-1][n-1] = 'o';
    printf("YES\n");
    for (int i = 0; i < n+n-1; ++i)
        printf("%s\n",ans[i]);

    return 0;
}