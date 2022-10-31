#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n, k, odd, even;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }
    if (n == k) {
        if (odd % 2) {
            cout << "Stannis" << endl;
        } else {
            cout << "Daenerys" << endl;
        }
        return 0;
    }
    int ans = (n - k) % 2;
    if ((n - k) / 2 >= min(odd, even)) {
        if (odd >= even) {
            if (k % 2 != (n - k) % 2) ans ^= 1;
        }
        else if ((n - k) % 2 != 0) ans ^= 1;
    }
    if (ans == 1) {
        cout << "Stannis";
    } else {
        cout << "Daenerys";
    }
    return 0;
}