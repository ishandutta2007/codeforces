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

int n, m;

string s[100];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            set<char> ss;
            ss.insert(s[i][j]);
            ss.insert(s[i + 1][j]);
            ss.insert(s[i][j + 1]);
            ss.insert(s[i + 1][j + 1]);
            if (ss.count('f') && ss.count('a') && ss.count('c') && ss.count('e')) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}