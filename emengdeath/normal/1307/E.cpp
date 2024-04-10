#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5011;
long long ansv, anssum;
int a[N];
int ni[N * N];
vector<int>w[N];
int suml[N], sumr[N], sl[N], sr[N];
int n, m;
long long sumv, vv;
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
int mul(int x, int y) {
    return 1ll * x * y <= mod ? x * y: 1ll * x * y % mod;
}
int ni_(int x) {
    return ni[x] ? ni[x] : ni[x] = mul(ni_(mod % x), (mod - mod / x));
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
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
inline int getint() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
void update(int x, bool sig) {
    int a = sl[x], b = sr[x];
    if (a > b) swap(a, b);
    int cnt1 = a + b, cnt2 = a * (b - 1);
    if (cnt2) {
        if (sig) {
            vv += 2;
            sumv = mul(sumv, cnt2);
        } else {
            vv -= 2;
            sumv = mul(sumv, ni_(cnt2));
        }
    } else
        if (cnt1) {
            if (sig) {
                vv ++;
                sumv = mul(sumv, cnt1);
            } else {
                vv --;
                sumv = mul(sumv, ni_(cnt1));
            }
        }

}
void update(int x, int*a, int v) {
    update(x, 0);
    a[x] = v;
    update(x, 1);
}

int add(int x, int y) {
    x+= y;
    return x >= mod ? x - mod : x;
}
void updateans(){
    if (ansv < vv) ansv = vv, anssum = sumv;
    else
        if (ansv == vv)anssum = add(anssum, sumv);
}
int main() {

    ni[0] = ni[1] = 1;
    n = getint();
    m = getint();
    for (int i = 2; i <= n;  i++) ni[i] = 1ll * ni[mod % i] * (mod - mod / i) % mod;
    for (int i= 1; i <= n; i ++) {
        a[i] = getint();
        w[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        x = getint(), y = getint();
        if (y > w[x].size()) continue;
        suml[w[x][y - 1]] ++;
        sumr[w[x][w[x].size() - y]] ++;
    }
    sumv = 1, vv = 0;
    for (int i = 1; i <= n; i ++)
        sr[a[i]] += sumr[i];
    for (int i = 1; i <= n; i ++) {
        int tmp = sr[i];
        sr[i] = 0;
        update(i, sr, tmp);
    }
    updateans();
    for (int i = 1; i <= n; i ++) {
        int tmpl = sl[a[i]] + suml[i], tmpr = sr[a[i]] - sumr[i];
        update(a[i], sr, 0);
        update(a[i], sl, 0);
        int tmpv = vv, tmpsum = sumv;
        int realr = tmpr, reall = tmpl;
        if (tmpr >= tmpl)
            tmpr --;
        tmpl = suml[i];
        int cnt1 = tmpr + tmpl, cnt2 = tmpr * tmpl;
        if (cnt2 && tmpl) {
            vv += 2;
            sumv = mul(sumv, cnt2);
            updateans();
        } else
            if (tmpl){
                vv += 1;
                sumv = mul(sumv, cnt1);
                updateans();
            } else {
                vv = tmpv, sumv = tmpsum;
                update(a[i], sr, realr);
                update(a[i], sl, reall);
                continue;
            }
        vv = tmpv, sumv = tmpsum;
        update(a[i], sr, realr);
        update(a[i], sl, reall);
    }
    if (!ansv) anssum = 1;
    printf("%lld %lld\n", ansv, anssum);
    return 0;
}