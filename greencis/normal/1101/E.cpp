#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int w = 0, h = 0; /// h <= w
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (x > y)
            swap(x, y);
        if (c == '+') { /// x <= y
            w = max(w, y);
            h = max(h, x);
        } else {
            cout << (w <= x || (h <= x && w <= y) ? "YES\n" : "NO\n");
        }
    }
}