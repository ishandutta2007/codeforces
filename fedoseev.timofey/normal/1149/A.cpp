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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int fir = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            fir = i;
            break;
        }
    }
    if (fir != -1 && a.size() > 1 && a[1] == 2) {
        swap(a[1], a[fir]);
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
}