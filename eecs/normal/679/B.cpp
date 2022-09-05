#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m, a[100010];
multiset<int> S;

int main() {
    scanf("%lld", &m);
    ll cur = 0, pos = 1;
    while (cur + pos * pos * pos <= m) {
        if (cur + pos * pos * pos < (pos + 1) * (pos + 1) * (pos + 1)) {
            cur += pos * pos * pos;
            a[pos]++, S.insert(pos);
        } else {
            pos++;
        }
    }
    auto chk = [&](ll x) {
        if (x > m) return 0;
        int num = 0;
        while (x) {
            ll y = pow(x, 1.0 / 3) - 1;
            while ((y + 1) * (y + 1) * (y + 1) <= x) y++;
            x -= y * y * y, num++;
        }
        return num;
    };
    int num = accumulate(a + 1, a + 100010, 0);
    while (1) {
        bool flag = 0;
        for (auto it = S.rbegin(); it != S.rend(); it++) {
            int i = *it;
            for (int j = 10; j; j--) {
                if (chk(cur - 1LL * i * i * i + 1LL * (i + j) * (i + j) * (i + j)) == num) {
                    a[i]--, a[i + j]++;
                    S.erase(S.find(i)), S.insert(i + j);
                    cur += 1LL * (i + j) * (i + j) * (i + j) - 1LL * i * i * i;
                    flag = 1; break;
                }
            }
            if (flag) break;
        }
        if (!flag) break;
    }
    printf("%d %lld\n", num, cur);
    return 0;
}