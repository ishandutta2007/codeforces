#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
bool isprime(T n) {
    if (n == 1) return false;
    for (T i = 2; i <= (T)(sqrt(n)); i++)
        if (n%i == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (n == 1 || n%2 == 0 && (isprime(n/2) && n%4 != 0 || __builtin_popcount(n) == 1 && n > 2) ? "FastestFinger\n" : "Ashishgup\n");
    }
}