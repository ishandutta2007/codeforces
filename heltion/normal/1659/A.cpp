#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, r, b;
        cin >> n >> r >> b;
        int p = r / (b + 1), q = r % (b + 1);
        for (int i = 0; i <= b; i += 1) {
            if (i) cout << "B";
            for (int k = 0; k < p + (i < q); k += 1)
                cout << "R";
        }
        cout << "\n";
    }
}