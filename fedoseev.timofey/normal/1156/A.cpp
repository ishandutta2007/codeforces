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
    int ans = 0;
    int lst = -1;
    int lst2 = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (lst != -1) {
            if ((lst == 1 && x == 2) || (lst == 2 && x == 1)) {
                ans += 3;
            }
            if ((lst == 1 && x == 3) || (x == 1 && lst == 3)) {
                ans += 4;
            }
            if ((lst == 2 && x == 3) || (x == 2 && lst == 3)) {
                cout << "Infinite\n";
                return 0;
            }
            if (x == 2 && lst == 1 && lst2 == 3) {
                --ans;
            }
        }
        lst2 = lst;
        lst = x;
    }
    cout << "Finite\n";
    cout << ans << '\n';
}