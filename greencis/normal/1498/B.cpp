#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll gcdsum(ll x) {
    ll tmp = x, sum = 0;
    while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
    }
    return gcd(x, sum);
}

int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, w;
        cin >> n >> w;
        vector<int> cnt(20);
        while (n--) {
            int x;
            cin >> x;
            x = __builtin_ctz(x);
            ++cnt[x];
        }
        int ans = 0;
        while (true) {
            vector<int> to_subtract(20);
            int cur = w;
            for (int i = 20; i--; ) {
                to_subtract[i] = min(cnt[i], cur / (1 << i));
                cur -= to_subtract[i] * (1LL << i);
            }
            if (cur == w)
                break;
            int how_many_can = 1e9;
            for (int i = 20; i--; )
                if (to_subtract[i] && cnt[i])
                    how_many_can = min(how_many_can, cnt[i] / to_subtract[i]);
            ans += how_many_can;
            for (int i = 20; i--; )
                cnt[i] -= how_many_can * to_subtract[i];
        }
        cout << ans << '\n';
    }
}