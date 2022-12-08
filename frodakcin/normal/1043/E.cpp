#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 100;
const int MAXM = 3e5 + 100;

int N, M;

typedef long long ll;

ll x[MAXN];
ll y[MAXN];

int v[MAXN];
ll vpx[MAXN], vpy[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 1;i <= N;i++) scanf("%lld%lld", x + i, y + i), v[i] = i;
    
    sort(v + 1, v + N + 1, [](const int& a, const int& b){return x[a] - y[a] < x[b] - y[b];});
    
    vpx[0] = vpy[0] = 0;
    for(int i = 1;i <= N;i++) {
        vpx[i] = vpx[i - 1] + x[v[i]];
        vpy[i] = vpy[i - 1] + y[v[i]];
    }
    
    ll ans[MAXN];
    
    for(int i = 0;i <= N;i++) ans[i] = 0;
    for(int i = 1;i <= N;i++) {
        ans[v[i]] = y[v[i]] * (i - 1) + vpx[i - 1] + x[v[i]] * (N - i) + vpy[N] - vpy[i];
    }
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ll v = min(x[a] + y[b], x[b] + y[a]);
        ans[a] -= v;
        ans[b] -= v;
    }
    
    for(int i = 1;i <= N;i++) printf("%lld ", ans[i]);
    
    printf("\n");
    return 0;
}