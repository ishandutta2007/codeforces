#include <iostream>
#include <cstdio>

#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll, int> pli;

const int MAXT = 1e5 + 100;
const ll INF = 2e18;
const int L = 62;

int T;
pli n[MAXT];
ll ans[MAXT];

ll pow(ll b, int p) {
    assert(p >= 0);
    if(p == 0) {if(b == 0) return -1; else return 1;}
    ll ret = 1;
    for(;p; b*=b) {
        if(p&1) {if(ret < INF/b) ret *= b; else return INF;}
        if((p>>=1) and b > INF/b) return INF;
    }
    return ret;
}

ll p[MAXT];
int mu[MAXT], ml[MAXT];

ll nroot(int r, ll v) {
    ll l = 0, h = p[r] + 1;
    while(h > l + 1) {
        ll m = l + (h - l)/2;
        if(v < pow(m, r)) h = m;
        else l = m;
    }
    return l;
}

void red(ll v) {
    int sw = 4;
    for(int i = 2;i < sw;i++) p[i] = nroot(i, v);
    for(int i = sw;i < L;i++) while(pow(p[i], i) > v) p[i]--;
}

ll count() {
    ll ret = 0;
    for(int i = 2;i < L;i++) if(p[i]) ret += (p[i] - 1) * mu[i];
    return ret;
}

int main() {
    for(int i = 1;i < L;i++) mu[i] = 1, ml[i] = i;
    for(int i = 2;i < L;i++) {
        for(int j = i * 2;j < L;j += i) {
            if(ml[i] == ml[j]) mu[j] = 0;
            else if(ml[i] < ml[j]) ml[j] = ml[i], mu[j] = 0;
            else if(ml[i] > ml[j]) mu[j] = -mu[i];
        }
    }
    
    //for(int i = 2;i < L;i++) printf("%d: %d\n", i, mu[i]);
    
    p[2] = 1e9;
    p[3] = 1e6;
    p[4] = 31700;
    p[5] = 4000;
    p[6] = 1000;
    for(int i = 7;i < L;i++) p[i] = 400;
    
    scanf("%d", &T);
    
    for(int i = 0;i < T;i++) scanf("%lld", &n[i].first), n[i].second = i;
    
    sort(n, n + T);
    
    for(int i = T - 1;i >= 0;i--) {
        red(n[i].first);
        ans[n[i].second] = (n[i].first - 1) - count();
        //cout << p[2] << endl;
    }
    
    for(int i = 0;i < T;i++) printf("%lld\n", ans[i]);
    
    return 0;
}