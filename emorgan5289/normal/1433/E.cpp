#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

ll fact(ll n) {
    if (n == 0) return 1;
    return n*fact(n-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    cout << fact(n) * 2 / (n*n) << "\n";
}