#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e3 + 100;
const int MAXM = MAXN;

typedef long long ll;
const ll INF = 1e18;

void solve(int l, ll * a, ll * p) {
    p[0] = 0;
    for(int s = 0, i = 0;s <= l;i = 0, p[++s] = INF) for(ll t = a[0];i < l;++i, t += a[i] - (i - s >= 0 ? a[i - s] : 0)) if(i + 1 >= s and t < p[s]) p[s] = t;
}
int N, M, ans;
ll a[MAXN], b[MAXM];
ll as[MAXN], bs[MAXM];
ll v;

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i < N;i++) scanf("%lld", a + i);
    for(int i = 0;i < M;i++) scanf("%lld", b + i);
    as[0] = bs[0] = 0;
    solve(N, a, as);
    solve(M, b, bs);
    scanf("%lld", &v);
    ans = 0;
    for(int x = 0, y = M, t;x <= N;x++) {
        while(as[x] * bs[y] > v) y--;
        if((t = x * y) > ans) ans = t;
    }
    printf("%d\n", ans);
    return 0;
}