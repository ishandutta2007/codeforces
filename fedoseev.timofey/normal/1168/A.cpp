#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = m;
    while (r - l > 1) {
        int md = (l + r) >> 1;
        int x = 0;
        bool fl = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] < x) {
                if (x - a[i] > md) {
                    fl = false;
                }
            }
            else if (a[i] > x) {
                if (m - (a[i] - x) > md) x = a[i];
            }
        }
        if (fl) r = md;
        else l = md;
    }
    cout << r << '\n';
}