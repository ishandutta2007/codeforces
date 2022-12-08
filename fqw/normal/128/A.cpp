#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = acos(-1);

template <class T> T sqr(T x) { return x * x; }
template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

bool c[1100][10][10];
char board[10][10];

const int dx[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
const int dy[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};

bool check(int x, int y, int t) {
    if (t <= x && board[x-t][y] == 'S')
        return false;
                           // printf("%d (%d,%d) board[x][y-t]=%c\n",t,x,y,board[x][y-t] );
    return true;
}

void solve() {
    forint (i, 0, 7)
        scanf("%s", board[i]);
    fillchar(c, false);
    bool flag = false;
    c[0][7][0] = true;
    forint (t, 0, 1000) {
        if (c[t][0][7])
            flag = true;
        forint (x, 0, 7)
            forint (y, 0, 7)
                if (c[t][x][y])
                    forint (i, 0, 8) {
                        int x0 = x + dx[i];
                        int y0 = y + dy[i];
                        if (x0 >= 0 && x0 <= 7 && y0 >= 0 && y0 <= 7 && check(x0, y0, t) && check(x0, y0, t+1))
                            c[t+1][x0][y0] = true;
                    }
    }
    printf("%s\n", flag ? "WIN" : "LOSE");
}

int main() {
    solve();
    return 0;
}