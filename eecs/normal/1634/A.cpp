#include <bits/stdc++.h>
using namespace std;

int T, n, K;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> K;
        string str;
        cin >> str;
        string foo = str;
        reverse(foo.begin(), foo.end());
        if (!K || str == foo) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}