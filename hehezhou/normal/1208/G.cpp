#include <bits/stdc++.h>
using namespace std;
int n, k;
int phi[1000010], np[1000010], prime[1000010], cnt;
long long ans;
int main() {
    scanf("%d%d", &n, &k);
    if(k == 1) return puts("3"), 0;
    phi[1] = np[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(np[i] == 0) prime[++cnt] = i, phi[i] = i - 1;
        for(int j = 1; prime[j] * i <= n; j++) {
            np[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    sort(phi + 1, phi + 1 + n);
    for(int i = 1; i <= k + 2; i++) ans += phi[i];
    return cout << ans << endl, 0;
}