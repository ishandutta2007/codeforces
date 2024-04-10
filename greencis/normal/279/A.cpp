#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int x,y;

int main()
{
    cin >> x >> y;
    int ans = 0;
    int len = 1;
    int dir = 0;
    int curmove = 0;
    int curx = 0;
    int cury = 0;
    while (!(curx == x && cury == y)) {
        if (dir == 0) ++curx;
        else if (dir == 1) ++cury;
        else if (dir == 2) --curx;
        else --cury;
        if (curx == x && cury == y) break;
        ++curmove;
        if (curmove == (len + 1) / 2) {
            curmove = 0;
            ++dir %= 4;
            ++len;
            ++ans;
        }
    }
    cout << ans;

    return 0;
}