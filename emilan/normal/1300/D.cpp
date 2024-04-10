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

    int n; cin >> n;
    pair<int, int> v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i].fi >> v[i].se;
    if (n % 2)
        cout << "NO";
    else {
        bool can = true;
        for (int i = 0; i < n / 2; i++) {
            if (v[i + 1].fi - v[i].fi != v[i + n / 2].fi - v[(i + 1 + n / 2) % n].fi
             || v[i + 1].se - v[i].se != v[i + n / 2].se - v[(i + 1 + n / 2) % n].se) {
                 can = false;
                 break;
             }
        }
        cout << (can ? "YES" : "NO");
    }

    return 0;
}