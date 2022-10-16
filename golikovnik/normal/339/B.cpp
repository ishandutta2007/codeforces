#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int s = (i > 0) ? a[i - 1] : 1;
        int t = a[i];
        ans += 1LL * (t >= s) ? (t - s) : (t + n - s);
    }
    cout << ans << endl;
    return 0;
}