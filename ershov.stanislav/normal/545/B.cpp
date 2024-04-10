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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

string s, t;
int n;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> s >> t;
    int n = (int) s.length();

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cnt++;
        }
    }
    if (cnt % 2 != 0) {
        cout << "impossible";
    } else {
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == t[i]) {
                cout << s[i];
            } else {
                if (j < cnt / 2) {
                    cout << s[i];
                } else {
                    cout << t[i];
                }
                j++;
            }
        }
    }
    return 0;
}