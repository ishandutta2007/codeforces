#include "bits/stdc++.h"

using namespace std;

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        set<char> s;
        s.insert(a[0]);
        s.insert(a[1]);
        s.insert(b[0]);
        s.insert(b[1]);
        cout << s.size() - 1 << "\n";
    }
}