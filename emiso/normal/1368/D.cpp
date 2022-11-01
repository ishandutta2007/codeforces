#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, freq[22], x;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        for(int b = 0; b <= 20; b++) {
            if(x & (1 << b)) freq[b]++;
        }
    }

    for(int i = 0; i < n; i++) {
        x = 0;
        for(int b = 0; b <= 20; b++) {
            if(freq[b]) {
                x += (1 << b);
                freq[b]--;
            }
        }
        ans += x * x;
    }

    printf("%lld\n", ans);
    return 0;
}