#include <bits/stdc++.h>
using namespace std;
int prime[100010], np[100010], n, k;
int cnt;
map <int, int> mp;
int main() {
    scanf("%d%d", &n, &k);
    np[1] = 1;
    for(int i = 2; i <= 100000; i++) {
        if(np[i] == 0) prime[++cnt] = i;
        for(int j = 1; prime[j] * i <= 100000; j++) {
            np[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        int now = 1, rest, tmp = 1, tag = 1;
        scanf("%d", &rest);
        for(int i = 1; prime[i] * prime[i] <= rest; i++) {
            int d = 0;
            while(rest % prime[i] == 0) d++, rest /= prime[i];
            d %= k;
            for(int j = 1; j <= d; j++) {
                tmp *= prime[i];
            }
            d = (k - d) % k;
            for(int j = 1; j <= d; j++) {
                now *= prime[i];
                if(now > 100000) {
                    tag = 0;
                }
            }
        }
        tmp *= rest;
        if(rest > 1) {
            int d = (k - 1) % k;
            for(int j = 1; j <= d; j++) {
                now *= rest;
                if(now > 100000) {
                    tag = 0;
                }
            }
        }
        if(tag) if(mp.count(now)) ans += mp[now];
        // cerr << now << ' ' << mp[now] << ' ' << tmp << endl;
        if(!mp.count(tmp)) mp[tmp] = 0;
        mp[tmp]++;
    }
    return cout << ans << endl, 0;
}