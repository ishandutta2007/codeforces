#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

    ll n, k; cin >> n >> k;
    if (k <= (n + 1) / 2)
        cout << 2 * k - 1;
    else
        cout << 2 * k - (n + 1) / 2 * 2;

    return 0;
}