#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll x, y;
vector<ll> ans;

void gcd(ll a, ll b) {
    if (!b) return;
    ans.push_back(a / b), gcd(b, a % b);
}

int main() {
    scanf("%lld %lld", &x, &y);
    if (__gcd(x, y) > 1) puts("Impossible"), exit(0);
    gcd(max(x, y), min(x, y)), ans.back()--;
    for (int i = 0, j = x < y; i < ans.size(); i++, j ^= 1) {
        printf("%lld%c", ans[i], j + 'A');
    }
    return 0;
}