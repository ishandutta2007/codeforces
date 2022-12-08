#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;
const int MAXL = 1e5 + 100;
const ll MAXS = 1e18 + 100;

int N, L;
ll S;

int p[MAXN];
ll w[MAXN];
bool check() {
    for(int i = 1;i <= N;i++) if(static_cast<ll>(w[i]) > S) return false;
    return true;
}
int u[MAXN];
bool v[MAXN];
int iot[MAXN], iotc, ans;
int h[MAXN];
ll d[MAXN];

void dfs(int i) {
    if(p[i] != 0 and !v[p[i]]) dfs(p[i]);
    v[i] = true, iot[iotc++] = i, h[i] = h[p[i]] + 1, d[i] = d[p[i]] + w[i];
}

int paint(int n, int b = -1) {
    if(n == 0) return 0;
    if(b == -1) b = n;
    if(u[n] != n) return (u[n] = paint(u[n], b));
    if(h[b] - h[p[n]] > L or d[b] - d[p[n]] > S) return n;
    return (u[n] = paint(p[n], b));
}

int main() {
    scanf("%d%d%lld", &N, &L, &S);
    for(int i = 1;i <= N;i++) scanf("%lld", w + i);
    if(!check()) {printf("-1\n"); return 0;}
    for(int i = 2;i <= N;i++) scanf("%d", p + i);
    for(int i = 0;i <= N;i++) u[i] = i, v[i] = false;
    p[1] = iotc = h[0] = ans = 0, p[0] = -1, d[0] = 0LL;
    for(int i = 1;i <= N;i++) if(!v[i]) dfs(i);
    for(int i = iotc - 1;i >= 0;i--) if(u[iot[i]] == iot[i]) ans++, assert(iot[i] != paint(iot[i]));
    printf("%d\n", ans);
    return 0;
}