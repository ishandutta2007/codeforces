#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2010;
int n, m;
char s[N][N];
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
struct node{
    int a[4], b[4];
}f[N][N];
int main() {
    n = getint();
    m = getint();
    for (int i = 1 ; i <= n; i ++) {
        for (int j = 1; j <= m; j ++){
            do {
                s[i][j] = getchar();
            } while (s[i][j] < 'a' || s[i][j] > 'z');
            f[i][j].a[0] = ((s[i][j] == s[i - 1][j]) *f[i - 1][j].a[0]) + 1;
            f[i][j].a[3] = ((s[i][j] == s[i][j - 1]) *f[i][j - 1].a[3]) + 1;
        }
    }
    for (int i = n; i >= 1; i --) {
        for (int j = m; j >= 1; j --) {
            f[i][j].a[1] = ((s[i][j] == s[i][j + 1]) *f[i][j + 1].a[1]) + 1;
            f[i][j].a[2] = ((s[i][j] == s[i + 1][j]) *f[i + 1][j].a[2]) + 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j] == s[i - 1][j - 1]) {
                f[i][j].b[0] = min(min(f[i - 1][j - 1].b[0] + 2, f[i][j].a[0]), f[i][j].a[3]);
            } else
                f[i][j].b[0] = min(min(f[i][j].a[0], f[i][j].a[3]), 2);
        }
        for (int j = m; j >= 1; j --) {
            if (s[i][j] == s[i - 1][j + 1]) {
                f[i][j].b[1] = min(min(f[i - 1][j + 1].b[1] + 2, f[i][j].a[0]), f[i][j].a[1]);
            } else
                f[i][j].b[1] = min(min(f[i][j].a[0], f[i][j].a[1]), 2);
        }
    }
    for (int i = n; i >= 1; i --) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j] == s[i + 1][j - 1]) {
                f[i][j].b[3] = min(min(f[i + 1][j - 1].b[3] + 2, f[i][j].a[2]), f[i][j].a[3]);
            } else
                f[i][j].b[3] = min(min(f[i][j].a[2], f[i][j].a[3]), 2);
        }
        for (int j = m; j >= 1; j --) {
            if (s[i][j] == s[i + 1][j + 1]) {
                f[i][j].b[2] = min(min(f[i + 1][j + 1].b[2] + 2, f[i][j].a[2]), f[i][j].a[1]);
            } else
                f[i][j].b[2] = min(min(f[i][j].a[2], f[i][j].a[1]), 2);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            ans += min(min(f[i][j].b[0], f[i][j].b[1]), min(f[i][j].b[2], f[i][j].b[3]));
    printf("%lld\n", ans);
    return 0;
}