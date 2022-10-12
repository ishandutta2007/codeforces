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
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll pos = 0, neg = 0;
        int psize = 0, nsize = 0;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            if (x > 0) {
                if (nsize+1 > psize) {
                    psize = nsize+1;
                    pos = -inf_ll;
                }
                if (nsize+1 == psize)
                    pos = max(pos, neg+x);
            } else {
                if (psize+1 > nsize) {
                    nsize = psize+1;
                    neg = -inf_ll;
                }
                if (psize+1 == nsize)
                    neg = max(neg, pos+x);
            }
        }
        debug(psize, nsize);
        if (psize == nsize) {
            cout << max(pos, neg) << "\n";
        } else if (psize > nsize) {
            cout << pos << "\n";
        } else {
            cout << neg << "\n";
        }
    }
}