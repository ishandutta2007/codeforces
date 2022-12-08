#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 1e9;
const int MAXC = 2e6 + 100;

int Q;
ll L, R;

ll prod(const ll& a, const ll& b) {
if(a == 0 or b == 0) return 0;
if(a >= INF/b) return INF;
return a * b;
}

ll pow(ll b, ll p) {
if(p == 0) return static_cast<ll>(1);
ll ret = pow(b, p/2);
ret = prod(ret, ret);
if(p%2) ret = prod(ret, b);
return ret;
}

int binsearch(ll * arr, const ll& g, const int& s) {
int l = -1, h = s;
while(h > l + 1) {
int m = (h + l)/2;
if(g < arr[m]) h = m;
else l = m;
}
return h;
}

ll v[MAXC];
int vs;

ll sqrt(const ll& a) {
    ll l = -1, h = a + 10;
    while(h > l + 1) {
        ll m = (l + h)/2;
        if(a < prod(m, m)) h = m;
        else l = m;
    }
    return h;
}

int main() {
vs = 0;
v[vs++] = 0;
for(int i = 3;i <= 60;i += 2){
ll r;
for(ll j = 2, t;true;j++) {
if(prod(t = sqrt(j) - 1, t) == j) continue;
r = pow(static_cast<ll>(j), static_cast<ll>(i));
if(r >= INF) break;
v[vs++] = r;
}
}
sort(v, v + vs);
vs = unique(v, v + vs) - v;

scanf("%d", &Q);
for(int i = 0;i < Q;i++) {
scanf("%lld%lld", &L, &R);
printf("%lld\n", (binsearch(v, R, vs) - binsearch(v, L - 1, vs) + sqrt(R) - sqrt(L - 1)));
}
}