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

const int m = 1000000007;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, h; fin >> n >> h;
    ll out = 1;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i]; a[i] = h-a[i];
        if (a[i] < 0) out = 0;
    }
    if (a[0] > 1 || a[n-1] > 1)
        out = 0;
    for (int i = 1; i < n; i++) {
        ll d = a[i-1]-a[i];
        if (abs(d) > 1)
            out = 0;
        if (d == 0 || d == 1)
            out = out*(a[i]+1)%m;
    }
    cout << out << "\n";
}