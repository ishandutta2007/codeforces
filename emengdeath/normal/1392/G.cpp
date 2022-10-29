#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 20;
const int M = 1e6 + 10;
char s[N], t[N];
int b[N], c[N], tmp[N];
int n, m, q;
int a[M][2];
int ans;
pair<int, int> ans1;
int l[1 << N][N + 1], r[1 << N][N + 1];
void turn(int*a, int*b, int*c) {
    for (int i = 0; i < n; i ++)
        tmp[i] = b[a[i]];
    for (int i = 0; i < n; i ++)
        c[i] = tmp[i];
}
int getv(int *a, char*s) {
    int v = 0;
    for (int i = 0; i < n; i ++)
        if (s[i])
            v |= (1 << a[i]);
    return v;
}
namespace IO {
    const int BUF_SIZE = 1 << 15;
    char in_buf[BUF_SIZE], out_buf[BUF_SIZE];
    char *p_in_buf = in_buf + BUF_SIZE;
    char *p_out_buf = out_buf;
    inline char get_char() {
        if (p_in_buf == in_buf + BUF_SIZE) {
            fread(in_buf, 1, BUF_SIZE, stdin), p_in_buf = in_buf;
        }
        return *(p_in_buf++);
    }
    inline void put_char(char x) {
        if (p_out_buf == out_buf + BUF_SIZE) {
            fwrite(out_buf, 1, BUF_SIZE, stdout), p_out_buf = out_buf;
        }
        *(p_out_buf++) = x;
    }
    inline void flush() {
        if (p_out_buf != out_buf) {
            fwrite(out_buf, 1, p_out_buf - out_buf, stdout);p_out_buf = out_buf;
        }
    }
}
#define getchar() IO::get_char()
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
inline int getint() {
    int x = 0;
    char c;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
template <class T>
inline void _putint(T x) {
    return x ? _putint(x / 10), putchar(48 + x % 10), void() : void();
}
template <class T>
inline void putint(T x) {
    return x == 0 ? putchar('0'), void() : _putint(x), void();
}
inline void getline(char *s) {
    char c = getchar();
    while (c == '\n') c = getchar();
    while (c != '\n') *(s++) = c, c = getchar();
    *s = 0;
}

int main() {
    q = getint();
    m = getint();
    n = getint();
    getline(s);
    getline(t);
    for (int i = 0; i < n;i ++)
        s[i] -= '0', t[i] -= '0';
    for (int i = 1; i <= q; i ++) {
        a[i][0] = getint() - 1; a[i][1] = getint() - 1;
    }
    for (int i = 0; i < n; i ++)
        b[i] = i;
    for (int i = 0; i < (1 << n); i ++)
        for (int j = 0; j <= n; j ++)
            l[i][j] = 1e9;
    for (int i = 1; i <= q; i ++) {
        int v = getv(b, s);
        l[v][__builtin_popcount(v)] = min(l[v][__builtin_popcount(v)], i);
        for (int j = 0; j < n; j ++)
            c[j] = j;
        swap(c[a[i][0]], c[a[i][1]]);
        turn(c, b, b);
        v = getv(b, t);
        r[v][__builtin_popcount(v)] = i;
    }
    ans = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < (1 << n); j ++)
            if (!(j&(1 << i))) {
                for (int k = 0; k <= n; k ++)
                    l[j][k] = min(l[j][k], l[j ^ (1<<i)][k]);
                for (int k = 0; k <= n; k ++)
                    r[j][k] = max(r[j][k], r[j ^ (1<<i)][k]);
            }
    ans1 = {1, 1};
    for (int i = 0; i < (1 << n); i ++)
        for (int j = 0; j <= n; j ++)
            for (int k = 0; k <= n; k ++)
                if (l[i][j] + m - 1 <= r[i][k] && ans < 2 * __builtin_popcount(i) + n - j - k)
                    ans = 2 * __builtin_popcount(i) + n - j - k, ans1 = {l[i][j], r[i][k]};
    printf("%d\n", ans);
    printf("%d %d\n", ans1.first, ans1.second);
    return 0;
}