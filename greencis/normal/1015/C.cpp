#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[100105];
int n;
ll m, sum;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        sum += x;
        a[i] = x - y;
    }
    sort(a, a + n, greater<int>());
    if (sum <= m) { cout << 0; return 0; }
    for (int i = 0; i < n; ++i) {
        sum -= a[i];
        if (sum <= m) { cout << i + 1; return 0; }
    }
    cout << -1;
}