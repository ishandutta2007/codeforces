#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;
int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i < n; i++) {
        ans += (n - i - 1) + (i - 2) + 1;
    }
    cout << ans << endl;
    return 0;
}