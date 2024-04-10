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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll a, b, n; cin >> a >> b >> n;
        if (a < b) swap(a, b);
        int x = 0;
        while (a <= n) {
            b += a;
            if (a < b) swap(a, b);
            x++;
        }
        cout << x << "\n";
    }
}