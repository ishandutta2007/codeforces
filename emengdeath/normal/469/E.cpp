#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long a;
pair<long long, long long> f[2][2][2];

void update(pair<long long, long long>& f, pair<long long, long long>b, int v) {
    f.first = min(a + 1, f.first + b.first);
    f.second = min((__int128)a + 1, (__int128)f.second + (__int128)b.second + (__int128)b.first * v);
}
long long get(__int128 l, __int128 r) {
    memset(f, 0, sizeof(f));
    bool bz = 0, bz1 = 1;
    f[0][1][1] = {1, 0};
    for (__int128 i = 1e36; i >= 1; i /= 10, swap(bz, bz1))
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 2; k ++) {
                for (int x = 0; x <= 9; x ++) {
                    if (j && x < l / i % 10) continue;
                    if (k && x > r / i % 10) continue;
                    update(f[bz1][j && x == l / i % 10][k && x == r / i % 10], f[bz][j][k], x);
                }
                f[bz][j][k] = {0, 0};
            }
    return min(f[bz][0][0].second + f[bz][1][0].second, a + 1) + min(f[bz][0][1].second + f[bz][1][1].second, a + 1);
}
#include <random>
#include <chrono>
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
void output(__int128 x) {
    if (x < 10)
        printf("%d", (int)x);
    else{
        output(x / 10);
        printf("%d", (int)(x % 10));
    }
}
int main() {
    scanf("%lld", &a);
    if (a <= 100) {
        for (int i = 1; i <= a; i ++)
            printf("1");
        puts("");
        for (int i = 1; i <= a; i ++)
            printf("1");
        return 0;
    }
    while (1) {
        __int128 l = rnd();
        while (l <= 0) {
            l = rnd();
        }
        __int128 r = l;
        for (long long i = (1ll << 62); i; i >>= 1)
            while (get(l, r + i) <= a) r += i;
        if (get(l, r) == a) {
            output(l);
            printf(" ");
            output(r);
            return 0;
        }
    }
    return 0;
}