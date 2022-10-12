#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5, K = 32;
int a[N], c[K];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(c, c+K, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int k = 0; k < K; k++)
                if (a[i]&(1<<k)) c[k]++;
        }
        for (int k = K-1; k >= 0; k--) {
            if (c[k]&1) {
                debug(c[k], n-c[k]);
                if ((n-c[k])%2 == 1)
                    cout << "WIN\n";
                else
                    cout << ((c[k]/2)%2 == 0 ? "WIN\n" : "LOSE\n");
                goto done;
            }
        }
        cout << "DRAW\n";
        done:;
    }
}