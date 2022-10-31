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

int n, t;

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> n >> t;
    if (n == 1) {
        if (t == 10) {
            cout << -1 << endl;
        }
        else {
            cout << t << endl;
        }
    } else {
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            res = (res * 10) % t;
        }
        printf("1");
        for (int i = 0; i < n - 2; i++) {
            printf("0");
        }
        printf("%c\n", '0' + (char)((t - res) % t));
    }
    return 0;
}