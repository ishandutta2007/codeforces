#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll a, b, x;

bool solve(ll a, ll b, ll x) {
    if (a > b) swap(a, b);
    if (!a || x > b) return 0;
    if (!((b - x) % a)) return 1;
    return solve(a, b % a, x);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &a, &b, &x);
        puts(solve(a, b, x) ? "YES" : "NO");
    }
    return 0;
}