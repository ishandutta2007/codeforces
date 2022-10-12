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
        ll n, l, r; fin >> n >> l >> r;
        ll off = 0;
        // l = 1, r = min(n*(n-1)+1, 100ll);
        while (n > 0 && l > 2*(n-1)) {
            l -= 2*(n-1);
            r -= 2*(n-1);
            off++;
            n--;
        }
        int k = 1;
        // debug(l, r, n);
        for (int j = n-1; j >= 1; j--) {
            for (int i = 1; i <= 2*j; i++) {
                if (k >= l && k <= r) {
                    if (i%2 == 1)
                        cout << 1+off << " ";
                    else
                        cout << (i/2)+1+off << " ";
                }
                if (k > r)
                    goto done;
                k++;
            }
            off++;
        }
        if (k <= r) {
            cout << "1 ";
        }
        done:;
        cout << "\n";
    }
}