#include <iostream>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;
const ll INF = 1e18;
int N;

typedef pair<int, int> pii;
#define mp make_pair
#define px first
#define py second

pii pts[MAXN];
ll dp[MAXN][2];
pii mn[MAXN][2];

int cmp1(const pii& a, const pii& b) {
    return max(b.px, b.py) - max(a.px, a.py);
}
bool cmp2(const pii& a, const pii& b) {
    assert(max(a.px, a.py) == max(b.px, b.py));
    return a.px == b.px ? a.py > b.py : a.px < b.px;
}
long long dist(const pii& a, const pii& b) {
    return static_cast<ll> (abs(b.px - a.px)) + static_cast<ll> (abs(b.py - a.py));
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d%d", &pts[i].px, &pts[i].py);
    
    sort(pts, pts + N, [](const pii& a, const pii& b){return max(a.px, a.py) < max(b.px, b.py);});
    
    int lvl = 0;
    
    for(int i = 0, j;i < N;i = j, lvl++) {
        for(int k = 0;k < 2;k++) mn[lvl][k] = pts[i];
        for(j = i + 1;j < N and cmp1(pts[i], pts[j]) == 0;j++) {
            if(cmp2(pts[j], mn[lvl][0])) mn[lvl][0] = pts[j];
            if(cmp2(mn[lvl][1], pts[j])) mn[lvl][1] = pts[j];
        }
    }
    
    ll fd = dist(mn[0][0], mn[0][1]);
    //printf("%d, %d -> %d,  %d\n", mn[0][0].px, mn[0][0].py, mn[0][1].px, mn[0][1].py);
    dp[0][0] = dist(mp(0, 0), mn[0][1]) + fd;
    dp[0][1] = dist(mp(0, 0), mn[0][0]) + fd;
    ll t;
    for(int i = 1;i < lvl;i++) {
        for(int j = 0;j < 2;j++) dp[i][j] = INF;
        fd = dist(mn[i][0], mn[i][1]);
        for(int j = 0;j < 2;j++) for(int k = 0;k < 2;k++) if((t = dp[i - 1][k] + dist(mn[i][j^1], mn[i - 1][k]) + fd) < dp[i][j]) dp[i][j] = t;
    }
    
    printf("%lld\n", min(dp[lvl - 1][0], dp[lvl - 1][1]));
    
    return 0;
}