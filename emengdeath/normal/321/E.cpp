#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4001;
int cnt[N];
long long f[N];
int g[N][N], a[N][N];
int n, m;
void work(long long d) {
    for (int i = 1; i <= n; i ++) {
        f[i] = 1e18;
        cnt[i] = 1e9;
        for (int j = 1; j <= i; j ++)
            if (f[j - 1] + g[j][i] + d < f[i] || (f[j - 1] + g[j][i] + d== f[i] && cnt[i] < cnt[j - 1] + 1))
                f[i] = f[j - 1] + g[j][i] + d, cnt[i] = cnt[j - 1] + 1;
    }
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

int main() {
    n = getint();
    m = getint();
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
            a[i][j] = getint();
    }
    for (int i = 1; i <= n; i ++) {
        int v = 0;
        for (int j = i; j >= 1; j --) {
            v += a[i][j];
            g[j][i] = g[j][i - 1] + v;
        }
    }
    long long l = 0, r = 1e9, mid, s = 0;
    while (l <= r)
    {
        work(mid = (l + r) / 2 );
        if (cnt[n] >= m)  {
            l = mid + 1;
            s = max(s, mid);
        } else
            r = mid - 1;
    }
    work(s);
    printf("%lld\n", f[n] - s * m);
    return 0;
}