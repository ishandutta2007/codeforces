#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        int a = 0, b = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x < a || y < b) good = false;
            if (y - b > x - a) good = false;
            a = x; b = y;
        }
        cout << (good ? "YES" : "NO") << endl;
    }
}