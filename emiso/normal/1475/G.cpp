#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], f[MN], dp[MN];
vector<int> divi[MN];

int main() {
    for(int i = 1; i <= 200020; i++)
        for(int j = i + i; j <= 200020; j += i)
            divi[j].push_back(i);

    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    ans = f[1];
    dp[1] = f[1];
    for(int i = 2; i < 200020; i++) {
        dp[i] = f[i];
        for(int j : divi[i])
            dp[i] = max(dp[i], f[i] + dp[j]);
        ans = max(ans, dp[i]);
    }

    printf("%lld\n", n - ans);
    for(int i = 0; i < n; i++) {
        f[a[i]] = 0;
    }
    if(--t) goto st;
    return 0;
}