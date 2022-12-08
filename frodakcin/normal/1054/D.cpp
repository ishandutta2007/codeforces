#include <iostream>
#include <cstdio>

#include <map>
#include <utility>

using namespace std;


const int MAXN = 2e5 + 1000;
const int MAXK = 31;

typedef long long ll;

int N, K;
int a[MAXN];
int p[MAXN];
int z;

map<int, int> mp;

ll c2(const ll& a) {
    if(a <= 0) return 0;
    return a*(a - 1)/2;
}

int main() {
    scanf("%d%d", &N, &K);
    z = (1 << K) - 1;
    p[0] = 0;
    for(int i = 1;i <= N;i++) scanf("%d", a + i), p[i] = p[i - 1] xor a[i];
    for(int i = 0;i <= N;i++) {
        if((p[i]^z) < p[i]) p[i] = p[i]^z;
        if(mp.find(p[i]) == mp.end()) mp.insert(make_pair(p[i], 1));
        else mp[p[i]]++;
    }
    
    ll ans = 0;
    for(map<int, int>::iterator it = mp.begin();it != mp.end();it++) ans += c2(static_cast<ll>(it->second/2)) + c2(static_cast<ll>((it->second + 1)/2));
    printf("%lld\n", c2(static_cast<ll> (N + 1)) - ans);
}