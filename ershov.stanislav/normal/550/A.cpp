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

int ab1 = INF, ab2, ba1 = INF, ba2;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    for (int i = 0; i < (int) s.length() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            ab1 = min(ab1, i);
            ab2 = i;
        }
        if (s[i] == 'B' && s[i + 1] == 'A') {
            ba1 = min(ba1, i);
            ba2 = i;
        }
    }
    if (ab1 < ba2 - 1 || ba1 < ab2 - 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}