#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

vector<bool> isp(MN, 1);
vector<int> primes;

void sieve() {
    isp[0] = isp[1] = 0;
    for(int i = 2; i < MN; i++) {
        if(isp[i]) primes.push_back(i);
        for(int j = 0; j < (int)primes.size() && i * primes[j] < MN; j++) {
            isp[i * primes[j]] = 0;
            if(i % primes[j] == 0) break;
        }
    }
}

int main() {
    sieve();
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    if(isp[sum]) {
        int notg = -1;
        for(int i = 0; i < n; i++)
            if(a[i] % 2 == 1) {
                notg = i;
                break;
            }

        printf("%lld\n", n - 1);
        for(int i = 0; i < n; i++) if(i != notg) printf("%d ", i + 1);
        puts("");
    } else {
        printf("%lld\n", n);
        for(int i = 0; i < n; i++) printf("%d ", i + 1);
        puts("");
    }

    if(--t) goto st;
    return 0;
}