#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<array<ll, 2>> a(n);
    for (auto& x : a) cin >> x[0] >> x[1];
    bool v = n%2 == 0;

    for (int i = 0; i < n/2; i++) {
        ll dx1 = a[(i+1)%n][0]-a[i][0];
        ll dy1 = a[(i+1)%n][1]-a[i][1];
        ll dx2 = a[(i+1+n/2)%n][0]-a[(i+n/2)%n][0];
        ll dy2 = a[(i+1+n/2)%n][1]-a[(i+n/2)%n][1];
        v &= dx1 == -dx2 && dy1 == -dy2;
    }
    cout << (v ? "YES" : "NO") << "\n";
}