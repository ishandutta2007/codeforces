#include <cstdio>

#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 10010;

int x, d, cnt;
ll cur = 1;
ll a[N];

int main() {
    scanf("%d%d", &x, &d);
    for (int k = 0; k <= 30; ++k)
        if ((x >> k) & 1) {
            a[++cnt] = cur;
            cur += d;
            for (int rep = 0; rep < k; ++rep)
                a[++cnt] = cur;
            cur += d;
        }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        printf("%lld ", a[i]);
    return 0;
}