#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 151500;

ll gcd(ll a, ll b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (a * b)/gcd(a, b);
}

int N;
int vals[MAXN][2];

int main() {
    ll ans = 0;
    scanf("%d", &N);
    for(int i = 0;i < N;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ans = gcd(ans, lcm(a, b));
        vals[i][0] = a;
        vals[i][1] = b;
    }
    for(int i = 0;i < N;i++) {
        ans = max(gcd(ans, vals[i][0]), gcd(ans, vals[i][1]));
    }
    printf("%lld\n", (ans == 1 ? -1 : ans));
}