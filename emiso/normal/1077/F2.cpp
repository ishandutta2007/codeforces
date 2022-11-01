#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, x;
ll a[5050], dp[5002][5002];

struct max_queue {
    deque<pair<ll, int>> v;

    void add(ll val, int pos) {
        while(!v.empty() && val > v.back().first) v.pop_back();
        v.emplace_back(val, pos);
    }

    void rem() {
        assert(!v.empty());
        v.pop_front();
    }

    pair<ll, int> max() {return v.front();}
};

int main() {
    scanf("%d %d %d", &n, &k, &x);

    for(int i = 0 ; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < 5002; i++)
        for(int j = 0; j < 5002; j++)
            dp[i][j] = -10000000000000000LL;

    dp[n][0] = 0;
    for(int X = 1; X <= x; X++) {
        max_queue mq;
        mq.add(dp[n][X-1], n);
        for(int pos = n-1; pos >= 0; pos--) {
            if(mq.max().second > pos + k) mq.rem();
            dp[pos][X] = a[pos] + mq.max().first;
            mq.add(dp[pos][X-1], pos);
        }
    }

    ll ans = -10000000000000000LL;
    for(int i = 0; i < k; i++)
        ans = max(ans, dp[i][x]);

    printf("%lld\n", max(-1LL, ans));
    return 0;
}