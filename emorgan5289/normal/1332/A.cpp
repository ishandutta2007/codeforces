#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int a, b, c, d; fin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2; fin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int m = min(a, b), n = min(c, d);

        if (x1 == x2 && m > 0 || y1 == y2 && n > 0) {
            cout << "NO\n"; continue;
        }
        a -= m; b -= m; c -= n; d -= n;
        if (x-a >= x1 && x+b <= x2 && y-c >= y1 && y+d <= y2) {
            cout << "YES\n"; continue;
        }
        cout << "NO\n";
    }
}