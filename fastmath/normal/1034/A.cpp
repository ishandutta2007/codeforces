#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;
const int MAXV = 2e7 + 7;

int a[MAXN];
int cnt[MAXV];
bool pr[MAXV];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr = __gcd(curr, a[i]);
    }
    
    for (int i = 0; i < MAXV; ++i) pr[i] = 1;
    for (int i = 2; i < MAXV; ++i) {
        if (pr[i]) {
            for (int j = 2 * i; j < MAXV; j += i) pr[j] = 0;
        }   
    }

    for (int i = 0; i < n; ++i) {
        a[i] /= curr;
        ++cnt[a[i]];
    }   

    int mx = 0;
    for (int i = 2; i < MAXV; ++i) {
        if (pr[i]) {
            int sum = 0;
            for (int j = i; j < MAXV; j += i) {
                sum += cnt[j];
            }
            mx = max(mx, sum);
        }
    }

    if (mx == 0) cout << "-1\n";
    else cout << n - mx << '\n';

    return 0;
}