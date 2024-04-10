#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

pii a[1005];
int n;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        a[i] = { -(q + w + e + r), i };
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (a[i].second == 0) {
            cout << i + 1;
            break;
        }
    }
}