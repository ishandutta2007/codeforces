#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int pos[100100];

int main() {
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n;
    int posi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x) pos[posi++] = i;
    }
    ll ans = 1e18;
    for (int k = 2; k <= posi; ++k) {
        if (posi % k) continue;
        ll cur = 0;
        for (int i = 0; i < posi; ) {
            int nxt = i + k;
            int mid = (i + nxt) / 2;
            while (i < nxt)
                cur += abs(pos[i++] - pos[mid]);
        }
        ans = min(ans, cur);
    }
    if (ans == ll(1e18)) ans = -1;
    cout << ans << endl;
}