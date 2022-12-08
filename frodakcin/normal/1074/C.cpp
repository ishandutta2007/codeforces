#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 1000;
const int INF = 1e9 + 1e6;

int N;
int x[MAXN];
int y[MAXN];

int mx[2], my[2];

ll peri(const int& x1, const int& x2, const int& y1, const int& y2) {
    assert(x1 <= x2 and y1 <= y2);
    if(x1 == x2 or y1 == y2) return 0;
    return 2LL*(static_cast<long long>(x2 - x1) + static_cast<long long>(y2 - y1));
}
void solve() {
    ll ans = 0, t;
    for(int i = 0;i < N;i++) {
        if((t = peri(mx[0], x[i], my[0], y[i])) > ans) ans = t;
        if((t = peri(mx[0], x[i], y[i], my[1])) > ans) ans = t;
        if((t = peri(x[i], mx[1], my[0], y[i])) > ans) ans = t;
        if((t = peri(x[i], mx[1], y[i], my[1])) > ans) ans = t;
    }
    printf("%lld ", ans);
}

int main() {
    scanf("%d", &N);
    mx[0] = my[0] = INF, mx[1] = my[1] = -INF;
    for(int i = 0;i < N;i++) {
        scanf("%d%d", x + i, y + i);
        if(x[i] < mx[0]) mx[0] = x[i];
        if(x[i] > mx[1]) mx[1] = x[i];
        if(y[i] < my[0]) my[0] = y[i];
        if(y[i] > my[1]) my[1] = y[i];
    }
    
    solve();
    ll ans = peri(mx[0], mx[1], my[0], my[1]);
    for(int i = 4;i <= N;i++) printf("%lld ", ans);
    printf("\n");
    
    return 0;
}