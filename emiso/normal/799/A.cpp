#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, t, k, d;
//char s[MN]; string str;

int main() {
    scanf("%lld %lld %lld %lld", &n, &t, &k, &d);
    ll t1 = (n + k - 1) / k * t;
    puts((d + t < t1) ? "YES" : "NO");
    return 0;
}