#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > mx) {
            cout << i + 1 << endl;
            return 0;
        }
        mx = max(mx, a + 1);
    }
    cout << -1 << endl;
}