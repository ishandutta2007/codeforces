#include <bits/stdc++.h>
using namespace std;

int main() {
    auto get = [&](string s) {
        cout << "next " << s << endl;
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> s;
        return n;
    };
    do {
        get("0 1");
    } while (get("0") ^ 2);
    while (get("0 1 2 3 4 5 6 7 8 9") ^ 1);
    cout << "done" << endl;
    return 0;
}