#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

map<int, ll> pd;

ll fexp(ll b) {
    if(b == 0) return 1;
    ll ans = fexp(b/2);
    ans = (ans * ans) % MOD;
    if(b & 1) ans = (ans * 2) % MOD;
    return ans;
}

ll find(ll x) {
    if(pd[x]) return pd[x];
    if(x == 1) return 2;
    ll total = 0;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            total = (total + find(x / i) - 1) % MOD;
            //printf("Total apos %lld eh %lld\n", x/i, total);
            if(x / i != i) {
                total = (total + find(i) - 1) % MOD;
                //printf("Total apos %lld eh %lld\n", i, total);
            }
        }
    }
    //printf("Find de %lld = %lld\n", x, (fexp(x-1) - total + MOD) % MOD);
    return pd[x] = (fexp(x-1) - total + MOD) % MOD;
}

int main() {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if(y % x) {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", find(y / x) - 1);
    return 0;
}