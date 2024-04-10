#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

unsigned long long h[1100000];
unsigned long long st[1100000];
int n,m;

vector<unsigned long long> sts;

uint64_t s[2];

uint64_t xorshift128plus(void) {
    uint64_t x = s[0];
    uint64_t const y = s[1];
    s[0] = y;
    x ^= x << 23; // a
    s[1] = x ^ y ^ (x >> 17) ^ (y >> 26); // b, c
    return s[1] + y;
}

int main() {
    srand(time(NULL));
    s[0]=rand();
    s[1]=rand();

    scanf("%d %d", &n, &m);

    REP(i,n) {
        h[i] = xorshift128plus();
    }
    
    REP(i,m) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        st[u] ^= h[v];
        st[v] ^= h[u];
    }

    sts.reserve(2*n);
    REP(i,n) {
        sts.push_back(st[i]);
        sts.push_back(st[i] ^ h[i]);
    }

    sort(sts.begin(), sts.end());
    
    int la = 0;
    long long ans = 0;
    for (int i = 0; i < sts.size(); i++) {
        if (i+1 == sts.size() || sts[i+1] != sts[la]) {
            int eq = i-la+1;
            ans += (eq)*1ll*(eq-1)/2;
            la = i+1;
        }
    }

    printf("%lld\n", ans);
}