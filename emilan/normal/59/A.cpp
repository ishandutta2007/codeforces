#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = 0;
    for (auto& i : s) {
        if ((i & ' ') == 0)
            n++;
    }

    if (n > s.size() / 2)
        transform(begin(s), end(s), begin(s), ::toupper);
    else
        transform(begin(s), end(s), begin(s), ::tolower);

    cout << s;

    return 0;
}