#include <iostream>
#include <cstdio>

#include <map>
#include <utility>
#include <vector>

#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<ll, vpii> maplvpi;

const int MAXN = 505000;
const int MAXM = 505000;
const int MAXK = 62;
const int MOD = 1e9 + 7;

int prod(int a, int b) {
    assert(a < MOD and b < MOD);
    return static_cast<int> ( (static_cast<ll> (a) * b) % MOD);
}
int sum(int a, int b) {
    assert(a < MOD and b < MOD);
    return static_cast<int> ( (static_cast<ll> (a) + b) % MOD);
}
int pow(int b, int p) {
    assert(p >= 0);
    if(p == 0) return 1;
    if(p == 1) return b;
    
    int ret = pow(b, p/2);
    ret = prod(ret, ret);
    if(p%2) ret = prod(ret, b);
    return ret;
}

int dsup[MAXN], dsus[MAXN], dsuch[MAXN], dsuchs;
void dsuinit(int s) {
    for(int i = 0;i <= s;i++) {
        dsup[i] = i;
        dsus[i] = 0;
    }
    dsuchs = 0;
}
int dsuf(int x) {
    if(dsup[x] == x) return x;
    return (dsup[x] = dsuf(dsup[x]));
}
bool dsum(int a, int b) {
    a = dsuf(a);
    b = dsuf(b);
    if(a == b) return false;
    if(dsus[a] < dsus[b]) swap(a, b);
    dsuch[dsuchs++] = b;
    dsup[b] = a;
    dsus[a] += dsus[b], dsus[b] = 0;
    return true;
}
void dsures1(int a) {
    dsus[a] = 1;
    dsup[a] = a;
}
void dsures() {
    while(dsuchs) {
        dsuchs--;
        dsures1(dsup[dsuch[dsuchs]]);
        dsures1(dsuch[dsuchs]);
    }
}

int N, M, K;
ll v[MAXN];
maplvpi groups;

int main() {
    scanf("%d%d%d", &N, &M, &K);
    
    for(int i = 1;i <= N;i++) scanf("%lld", v + i);
    
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ll d = v[a] xor v[b];
        groups[d].pb(mp(a, b));
    }
    
    dsuinit(N);
    
    int ans = 0, ctr = 0;
    for(maplvpi::iterator it = groups.begin();it != groups.end();it++) {
        ctr++;
        int r = 0;
        for(int i = 0;i < it->second.size();i++) {
            if(dsum(it->second[i].first, it->second[i].second)) r++;
        }
        ans = sum(ans, pow(2, N - r));
        dsures();
    }
    ans = sum(ans, prod(pow(2, N), static_cast<int>(((1LL << K) - ctr) % MOD)));
    
    printf("%d\n", ans);
    
    return 0;
}