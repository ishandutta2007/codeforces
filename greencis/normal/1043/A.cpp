#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[105], mx, sum;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    while (n * mx - sum <= sum)
        ++mx;
    cout << mx << endl;
}