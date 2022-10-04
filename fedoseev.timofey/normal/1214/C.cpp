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
    string s;
    cin >> s;
    int bal = 0;
    int mn = 0;
    for (char c : s) {
        if (c == ')') --bal;
        else ++bal;
        mn = min(mn, bal);
    }
    if (bal == 0 && mn >= -1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}