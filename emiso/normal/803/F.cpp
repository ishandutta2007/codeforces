#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define M 1000000007

using namespace std;
typedef long long ll;

ll n, a[MN], mul[MN], maxi = -1, ex[MN];
bitset <MN> primo;
vector<ll> ps;

void crivo() {
    primo.flip();
    primo[1] = 0;

    for(int i=2; i*i < MN;i++) {
        if(primo[i]) {
            for(int j = i*i; j < MN; j += i)
                primo[j] = 0;
        }
    }

    for(int i=2; i < MN;i++) {
        if(primo[i]) {
            ps.push_back(i);
        }
    }
}

void upd(ll x, ll m = 1, int pi = 0) {
    for(int i=1; i*i<=x;i++) {
        if(x % i == 0) {
            mul[i]++;
            if(i != x / i) mul[x / i]++;
        }
    }
}

long long exp(long long b, long long n) {
    if(n==0) return 1;
    if(n%2 == 0) return exp((b*b)%M,n/2);
    return (b*exp(b,n-1))%M;
}

ll exp(ll n) {
    if(ex[n] != 0) return ex[n];
    return ex[n] = exp(2, n);
}

ll solve(ll val = 1, int id = 0) {
    if(ps[id] > maxi) return 0;
    if(val * ps[id] > maxi) return 0;
    if(mul[val] == 0) return 0;

    ll p = ps[id];

    ll ret = (exp(mul[val * p]) - 1 + M) % M;
    ret = (ret + (solve(val, id + 1))) % M;
    ret = (ret - (solve(val * p, id + 1)) + M) % M;

    return ret;
}

int main() {
    scanf("%lld", &n);
    crivo();

    for(int i=0; i<n; i++) {
        scanf("%lld",&a[i]);

        maxi = max(maxi, a[i]);
        upd(a[i]);
    }

    ll ret = (exp(n) - 1 + M) % M;
    printf("%lld\n", (ret - solve() + M) % M);
    return 0;
}