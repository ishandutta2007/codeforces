#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int n;
int a[N];
vector<int> g[2];
long long work(int v, int x) {
    long long ans = 0;
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r < n && (a[r+1] >> (x + 1)) == (a[l] >> (x + 1))) r ++;
        int sum0 = 0, sum1 = 0;
        for (int i = l; i <= r; i ++)
            if (((a[i] >> x) & 1) ^ v) {
                sum1 ++;
            } else {
                sum0 ++;
                ans += sum1;
            }
        l = r + 1;
    }
    return ans;
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
    //freopen("input", "r", stdin);
    n = getint();
    for (int i =  1; i <= n;i ++)
        a[i] = getint();
    long long all = 0;
    int v = 0;
    for (int i = 29; i >= 0; i --) {
        for (int j = 1; j <= n;j ++)
            g[(a[j] >> (i+ 1)) & 1].push_back(a[j]);
        int cnt = 0;
        for (auto u:g[0])
            a[++cnt] = u;
        for (auto u:g[1])
            a[++cnt] = u;
        g[0].clear();
        g[1].clear();
        if (i == 0) {
            int yy;
            yy = 0;
        }
        long long sum0 = work(0, i);
        long long sum1 = work(1, i);

        if (sum0> sum1) {
            v |= (1 << i);
            all += sum1;
        } else all += sum0;
    }
    printf("%lld %d\n", all, v);

    return 0;
}