#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a, x[100105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> a;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    if (n == 1) { cout << 0; return 0; }
    sort(x + 1, x + n + 1);
    int ans = 2e9;
    ans = min(ans, abs(a - x[2]) + x[n] - x[2]);
    ans = min(ans, abs(a - x[1]) + x[n - 1] - x[1]);
    ans = min(ans, abs(a - x[n - 1]) + x[n - 1] - x[1]);
    ans = min(ans, abs(a - x[n]) + x[n] - x[2]);
    cout << ans << endl;

    return 0;
}