#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, a, b; cin >> n >> a >> b;
        if (a+b > n-2 || abs(a-b) > 1)
            cout << "-1\n";
        else {
            if (a > b) {
                int l = 2, r = n;
                cout << 1;
                for (int i = 0; i < b; i++)
                    cout << " " << r-- << " " << l++;
                for (int i = 2*b; i < n-1; i++)
                    cout << " " << r--;
            }
            if (a < b) {
                int l = 1, r = n-1;
                cout << n;
                for (int i = 0; i < a; i++)
                    cout << " " << l++ << " " << r--;
                for (int i = 2*a; i < n-1; i++)
                    cout << " " << l++;
            }
            if (a == b) {
                int l = 2, r = n;
                cout << 1;
                for (int i = 0; i < b; i++)
                    cout << " " << r-- << " " << l++;
                for (int i = 2*b; i < n-1; i++)
                    cout << " " << l++;
            }
            cout << "\n";
        }
    }
}