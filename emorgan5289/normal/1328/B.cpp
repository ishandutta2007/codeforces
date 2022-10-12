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
    ll t; fin >> t;
    while (t--) {
        ll n, k; fin >> n >> k;
        string out = "";
        ll b = 2;
        for (ll i = 0; i < n; i++) {
            ll lower;
            if (b == 2)
                lower = (n-i-1)*(n-i-2)/2;
            else if (b == 1)
                lower = (n-i-1);
            else lower = 1;
            if (lower < k) {
                out += 'b'; k -= lower; b--;
            } else
                out += 'a';
        }
        cout << out << "\n";
    }
}