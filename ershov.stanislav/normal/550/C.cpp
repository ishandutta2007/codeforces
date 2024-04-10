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

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int n = s.length();
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' == 0 || s[i] == '8') {
            ans = s[i] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = s[i] - '0';
            a *= 10;
            a += s[j] - '0';
            if (a % 8 == 0) {
                ans = a;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = s[i] - '0';
                a *= 10;
                a += s[j] - '0';
                a *= 10;
                a += s[k] - '0';
                if (a % 8 == 0) {
                    ans = a;
                }
            }
        }
    }
    if (ans != -1) {
        cout << "YES" << endl << ans << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}