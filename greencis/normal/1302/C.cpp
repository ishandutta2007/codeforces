#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, d;
        cin >> n >> d;
        int ans;
        cin >> ans;
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            int mv = min(d / i, x);
            d -= mv * i;
            ans += mv;
        }
        cout << ans << endl;
    }
}