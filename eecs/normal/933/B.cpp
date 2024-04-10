#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
vector<ll> V;

int main() {
    scanf("%lld %lld", &n, &k);
    ll s = n;
    while (s != 0) {
        ll x = -s / k;
        while (s + x * k < 0) x++;
        while (s + x * k >= k) x--;
        V.push_back(s + x * k);
        s = x;
    }
    printf("%d\n", V.size());
    for (int x : V) printf("%d ", x);
    return 0;
}