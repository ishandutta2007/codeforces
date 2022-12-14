#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int p = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s[p] == t[i])
            p++;
    }

    cout << p + 1;

    return 0;
}