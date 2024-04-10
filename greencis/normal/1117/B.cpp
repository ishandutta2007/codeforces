#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k;
int a[200105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    ll cnt = m / (k + 1);
    cout << cnt * a[1] + (m - cnt) * a[0];
}