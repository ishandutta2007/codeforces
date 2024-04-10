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
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'n') ++cnt1;
        if (c == 'z') ++cnt0;
    }
    for (int i = 0; i < cnt1; ++i) cout << "1 ";
    for (int i = 0; i < cnt0; ++i) cout << "0 ";
}