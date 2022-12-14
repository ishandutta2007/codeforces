#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> s;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << 4 - s.size();

    return 0;
}