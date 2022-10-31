#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define fs first
#define sc second

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

int main () {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(a + b + c, min((a + c) * 2, min((b + c) * 2, (a + b) * 2))) << endl;
}