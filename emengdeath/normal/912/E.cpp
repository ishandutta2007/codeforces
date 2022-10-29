#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long m;
int d[16];
long long q[10000000], w[10000000];
void work(int* d, int step, long long v, long long mx, long long * q) {
    if (!step) {
        q[++q[0]] = v;
        return;
    }
    while (1){
        work(d + 1, step - 1, v, mx, q);
        if (mx / v >= d[0])
        {
            v *= d[0];
        } else
            break;
    }
}
long long get(long long x) {
    long long v = 0;
    int cnt = upper_bound(q + 1, q + q[0] + 1, x) - q - 1;
    for (int i = 1; i <= w[0] && w[i] <= x; i ++)
    {
        while (x / q[cnt] < w[i]) cnt --;
        v += cnt;
    }
    return v;
}

int b[16];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &b[i]);
    sort(b, b + n);
    int cnt = 0;
    for (int i = 0; i < n; i += 2)
        d[cnt ++] = b[i];
    for (int i = 1; i < n; i += 2)
        d[cnt ++] = b[i];
    scanf("%lld", &m);
    work(d, n / 2, 1, 1e18, q);
    work(d + n / 2, n - n / 2, 1, 1e18, w);
    sort(q + 1, q + q[0] + 1);
    sort(w + 1, w + w[0] + 1);
    long long l = 1, r = 1e18, mid, s = r;
    while (l <= r) {
        if (get(mid = (l + r) / 2) >= m) s = min(s, mid), r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld\n", s);
    return 0;
}