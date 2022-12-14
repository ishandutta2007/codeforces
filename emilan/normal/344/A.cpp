#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s_prev = "-1";
    int co = 0, n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        
        if (s != s_prev)
            co++;
        s_prev = s;
    }

    cout << co;

    return 0;
}