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
string s[500];
int cnt[500][500];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                cnt[i][j]++;
            } else {
                cnt[i][j]--;
            }
        }
    }
    for (int sum = n + m - 2; sum >= 0; sum--) {
        for (int i = 0; i <= sum; i++) {
            int j = sum - i;
            if (i < n && j < m) {
                int c = cnt[i][j + 1] + cnt[i + 1][j] - cnt[i + 1][j + 1] - cnt[i][j];
                if (c != 0) {
                    ans++;
//                    cout << i << ' ' << j << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}