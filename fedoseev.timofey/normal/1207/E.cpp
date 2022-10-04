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
    cout << "? ";
    for (int i = 0; i < 100; ++i) cout << i << ' ';
    cout << endl;
    int a;
    cin >> a;
    cout << "? ";
    for (int i = 1; i <= 100; ++i) cout << (i << 7) << ' ';
    cout << endl;
    int b;
    cin >> b;
    a &= ~((1 << 7) - 1);
    b &= ((1 << 7) - 1);
    cout << "! " << (a | b) << endl;
}