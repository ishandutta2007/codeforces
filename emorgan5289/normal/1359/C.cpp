#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

double x, y;
double d(ll k) {
    return x-double(1)/(4*k+2)*y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int q; cin >> q;
    while (q--) {
        ll h, c, t; cin >> h >> c >> t;
        x = t-double(h+c)/2; y = h-c;
        ll a = 0, b = 1e9;
        if (2*t <= h+c) {
            cout << "2\n"; continue;
        }
        while (a < b) {
            ll k = (a+b)/2;
            if (d(k) < 0)
                a = k+1;
            else
                b = k;
        }
        cout << (abs(d(a)) < abs(d(a-1)) ? (2*a+1) : (2*a-1)) << "\n";
    }
}