#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, l, a;
int x[100105], y[100105];
int ans;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> a;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        ans += (x[i] - (x[i - 1] + y[i - 1])) / a;
    }
    ans += (l - x[n] - y[n]) / a;
    cout << ans << endl;
}