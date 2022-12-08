#include <iostream>
#include <cstdio>

#include <utility>
#include <queue>

#include <cassert>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 100;
const int MAXK = 5e3 + 100;
const int MAXX = 5e3 + 100;

int N, K, X, a[MAXN];

ll dp[MAXN][MAXX];

typedef pair<ll, int> pii;
#define mp make_pair
#define ff first
#define ss second
typedef deque<pii> qpii;

qpii dp2[MAXX];
void add(qpii& q, pii v) {
    while(!q.empty() and v.ff > q.back().ff) q.pop_back();
    q.push_back(v);
}
ll getn(qpii& q, int cut) {
    while(!q.empty() and q.front().ss < cut) q.pop_front();
    if(q.empty()) return -1;
    return q.front().ff;
}

int main() {
    scanf("%d%d%d", &N, &K, &X);
    if(K > N) K = N;
    
    for(int i = 1;i <= N;i++) scanf("%d", a + i);
    
    for(int i = 0;i <= N;i++) for(int j = 0;j <= X;j++) dp[i][j] = -1LL;
    
    dp2[0].push_back(mp(0, K));
    for(int i = 1;i <= N;i++) {
        for(int j = X;j > 0;j--) {
            dp[i][j] = getn(dp2[j-1], i);
            if(dp[i][j] != -1) {
                dp[i][j] += a[i];
                add(dp2[j], mp(dp[i][j], i + K));
            }
        }
    }
    
    ll ans = -1;
    for(int i = 0;i < K;i++) if(dp[N-i][X] > ans) ans = dp[N-i][X];
    printf("%lld\n", ans);
    
    return 0;
}