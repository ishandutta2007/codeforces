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

const int MOD = 1e9 + 7;

int n;

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> n;
    ll ans = 1, ans2 = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * 7) % MOD;
        ans2 = (ans2 * 27) % MOD;
    }
    cout << (ans2 + MOD - ans) % MOD;
    return 0;
}