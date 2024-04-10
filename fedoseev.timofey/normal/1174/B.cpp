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
    int n;
    cin >> n;
    vector <int> a(n);
    bool fl1 = false, fl2 = false;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	if (a[i] & 1) fl1 = true;
    	else fl2 = true;
    }
    if (fl1 && fl2) {
    	sort(a.begin(), a.end());
    }
    for (auto x : a) cout << x << ' ';
}