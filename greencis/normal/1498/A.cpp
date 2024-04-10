#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll gcdsum(ll x) {
    ll tmp = x, sum = 0;
    while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
    }
    return gcd(x, sum);
}

int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll n;
        cin >> n;
        while (gcdsum(n) == 1)
            ++n;
        cout << n << '\n';
    }
}