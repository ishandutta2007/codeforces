#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
#define jh(x, y) x^=y^=x^=y
#define rg register
#define inl inline
typedef long long ll;
const int N = 5e5 + 5, mod = 998244353, INF = 0x3f3f3f3f;
using namespace std;
namespace fast_IO {
    inl ll read() {
        rg char c;
        rg ll x = 0;
        rg bool flag = false;
        while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
        if (c == EOF)return c; if (c == '-')flag = true; else x = c ^ 48;
        while ((c = getchar()) != ' ' && c != '\n' && c != '\r'&&~c)
            x = (x << 1) + (x << 3) + (c ^ 48);
        if (flag)return -x; return x;
    }
    inl ll max(rg ll a, rg ll b) { if (a > b)return a; return b; }
    inl ll min(rg ll a, rg ll b) { if (a < b)return a; return b; }
    void write(rg ll x) { if (x < 0)putchar('-'), x = -x; if (x >= 10)write(x / 10); putchar(x % 10 ^ 48); }
}
char s[N], t[N];
int lx[5], dui[2][5], p[5][N], n;
inl void judge(rg int x1, rg int x2)
{
    memset(dui, 0, sizeof(dui));
    rg int c3 = lx[3], c4 = lx[4];
    if (x2 < 0 || x2>lx[2])return;
    dui[0][1] = x1, dui[0][2] = x2;
    dui[0][0] = x1 + x2;
    dui[1][1] = lx[1] - x1, dui[1][2] = lx[2] - x2;
    dui[1][0] = lx[1] - x1 + lx[2] - x2;
    while (c3&&dui[1][3] + dui[1][2] < dui[0][4] + dui[0][2])--c3, ++dui[1][3], ++dui[1][0];
    while (c4&&dui[1][3] + dui[1][2] > dui[0][4] + dui[0][2])--c4, ++dui[0][4], ++dui[0][0];
    if (dui[1][3] + dui[1][2] != dui[0][4] + dui[0][2])return;
    if (dui[1][0] > n / 2 || dui[0][0] > n / 2)return;
    if (c3 < c4)dui[1][3] += c3, dui[0][4] += c3, dui[1][4] += c3, dui[0][0] += c3, dui[1][0] += c3, c4 -= c3, c3 = 0;
    else dui[1][3] += c4, dui[0][4] += c4, dui[1][4] += c4, dui[0][0] += c4, dui[1][0] += c4, c3 -= c4, c4 = 0;
    if (dui[0][0] < n / 2)dui[0][3] += c3, dui[0][0] += c3;
    if (dui[1][0] < n / 2)dui[1][4] += c4, dui[1][0] += c4;
    if (dui[0][0] + dui[1][0] != n || dui[0][0] != dui[1][0] || dui[0][2] + dui[0][4] != dui[1][2] + dui[1][3])return;
    for (rg int i = 1; i <= 4; ++i)
    {
        for (rg int j = 1; j <= dui[0][i]; ++j)
            fast_IO::write(p[i][j]), putchar(' ');
    }
    exit(0);
}
int main(void)
{
    n = fast_IO::read();
    scanf("%s%s", s + 1, t + 1);
    for (rg int i = 1; i <= n; ++i)
    {
        if (s[i] == t[i]) { if (s[i] == '0')++lx[1], p[1][++*p[1]] = i; else ++lx[2], p[2][++*p[2]] = i; }
        else { if (s[i] == '0')++lx[3], p[3][++*p[3]] = i; else ++lx[4], p[4][++*p[4]] = i; }
    }
    for (rg int x1 = 0; x1 <= lx[1]; ++x1)
        judge(x1, lx[2] + lx[3] - n / 2 + x1);
    puts("-1");
    return 0;
}