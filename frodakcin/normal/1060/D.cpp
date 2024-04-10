#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;

typedef long long ll;

int N, l[MAXN], r[MAXN];

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d%d", l + i, r + i);
    sort(l, l + N);
    sort(r, r + N);
    ll ans = N;
    for(int i = 0;i < N;i++) ans += max(l[i], r[i]);
    printf("%lld\n", ans);
    return 0;
}