#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    cout << "0 0" << endl;
    string c0;
    cin >> c0;
    int l = 1, r = 1e9;
    for (int i = 1; i < n; i++) {
        int mid = (l + r) >> 1;
        cout << mid << " " << mid << endl;
        string c; cin >> c;
        if (c == c0) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << " " << l << " " << l << " " << l - 1 << endl;
    return 0;
}