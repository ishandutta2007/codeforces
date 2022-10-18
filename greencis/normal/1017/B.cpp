#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll cnt[4];
string a, b;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
        ++cnt[(a[i] - '0') * 2 + (b[i] - '0')];
    ll ans = cnt[0] * cnt[2] + cnt[0] * cnt[3] + cnt[1] * cnt[2];
    cout << ans;
}