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
    char min_let = 'z';
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (min_let < s[i]) {
            cout << "Ann\n";
        } else {
            cout << "Mike\n";
        }
        min_let = min(min_let, s[i]);
    }
}