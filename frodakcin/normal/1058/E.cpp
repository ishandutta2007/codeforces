#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 300000 + 10;

int N;

int a[MAXN], dp[2][2], s[MAXN];

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) {
        ll r;
        scanf("%lld", &r);
        a[i + 1] = __builtin_popcountll(r);
    }
    a[0] = 0;
    s[0] = 0;
    for(int i = 1;i <= N;i++) s[i] = s[i - 1] + a[i];
    
    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) dp[i][j] = 0;
    
    ll ans = 0;
    
    bool cur = true;
    dp[!cur][0] = 0;
    for(int i = 1;i <= N;i++) {
        for(int j = 0;j < 2;j++) {
            dp[cur][j] = dp[!cur][j ^ (a[i]&1)];
        }
        ans += dp[cur][0];
        dp[cur][a[i]&1]++;
        cur = !cur;
    }
    
    for(int i = 1;i <= N;i++) {
        int l = a[i];
        for(int j = i - 1;j > 0 and s[i] - s[j - 1] <= 130;j--) {
            if(a[j] > l) l = a[j];
            if(((s[i] - s[j - 1])&1) == 0 and l * 2 > s[i] - s[j - 1]) ans--;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}