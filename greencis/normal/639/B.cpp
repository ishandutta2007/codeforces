#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n, d, h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> d >> h;
    if (d == 1) {
        if (n == 2) { cout << "1 2"; }
        else cout << "-1";
        return 0;
    }
    if (d > 2 * h) { cout << "-1"; return 0; }

    for (int i = 1; i <= h; ++i) {
        cout << i << " " << i + 1 << "\n";
    }
    if (d - h > 0) {
        cout << 1 << " " << h + 2 << "\n";
        for (int i = 0; i < d - h - 1; ++i)
            cout << h + 2 + i << " " << h + 3 + i << "\n";
        for (int i = d + 1; i <= n - 1; ++i)
            cout << 1 << " " << i + 1 << "\n";
    } else {
        for (int i = h + 2; i <= n; ++i)
            cout << 2 << " " << i << "\n";
    }

    return 0;
}