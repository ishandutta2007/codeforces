#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ll a = 1, n;
    for (ll i = 2; i <= 10; ++i)
        a = a / gcd(a, i) * i;
    cin >> n;
    cout << n / a;
    return 0;
}