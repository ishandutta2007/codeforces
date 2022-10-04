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
    string s;
    cin >> s;
    if ((int)s.size() % 2 == 0) cout << (int)s.size() / 2 << '\n';
    else {
    	bool fl = false;
    	for (int i = 1; i < (int)s.size(); ++i) fl |= (s[i] == '1');
    	cout << (int)s.size() / 2 + fl << '\n';
    }
}