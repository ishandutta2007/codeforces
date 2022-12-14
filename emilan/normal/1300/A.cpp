#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int zero = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            if (!m)
                zero++;
            else   
                sum += m;
        }
        if (-sum == zero)
            cout << zero + 1 << '\n';
        else
            cout << zero << '\n';
    }

    return 0;
}