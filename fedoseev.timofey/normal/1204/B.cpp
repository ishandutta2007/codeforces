#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, l, r;
    cin >> n >> l >> r;
    ll mn = 0, mx = 0;
	mn += n - l;
	for (int i = 0; i < l; ++i) mn += (1 << i);
	mx += (n - r) * (1 << (r - 1));
	for (int i = 0; i < r; ++i) mx += (1 << i);
    cout << mn << ' ' << mx << '\n';
}