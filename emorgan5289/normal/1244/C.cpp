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
    ll n, p, w, d; fin >> n >> p >> w >> d;
    ll g = __gcd(w, d);
    if (p%g != 0) {
        cout << "-1\n"; return 0;
    }
    p /= g; w /= g; d /= g;
    for (int i = 0; i < min(w, p/d+1); i++)
        if ((p-d*i)%w == 0 && (n-i-(p-d*i)/w) >= 0) {
            cout << (p-d*i)/w << " " << i << " " << (n-i-(p-d*i)/w) << "\n";
            return 0;
        }
    cout << "-1\n";
}