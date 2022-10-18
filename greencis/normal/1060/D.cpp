#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, l[100105], r[100105];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    sort(l, l + n);
    sort(r, r + n);
    for (int i = 0; i < n; ++i)
        ans += 1 + max(l[i], r[i]);
    cout << ans << endl;
}