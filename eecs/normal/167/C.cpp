#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;

bool calc(ll rem, ll x) {
    if (x & 1) return (rem + 1) % 2;
    if (rem % (x + 1) == 0) return 1;
    rem -= rem / (x + 1);
    return (rem + 1) % 2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        vector<bool> V;
        while (a && b) {
            if (a > b) swap(a, b);
            V.push_back(calc(b / a, a)), b %= a;
        }
        bool cur = 1;
        reverse(V.begin(), V.end());
        for (bool x : V) {
            if (cur) cur = 0;
            else cur = !x;
        }
        puts(!cur ? "First" : "Second");
    }
    return 0;
}