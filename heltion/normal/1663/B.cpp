#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    vector<int> v = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    for (int x : v) if (r < x) {
        cout << x;
        break;
    }
    return 0;
}