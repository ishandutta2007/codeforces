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

int n;
string s[111];
int cnt[111];
int g[111];
vector<int> ans;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    while (true) {
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == g[i]) {
                j = i;
            }
        }
        if (j == -1) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (s[j][i] == '1') {
                cnt[i]++;
            }
        }
        ans.pb(j);
    }
    cout << (int) ans.size() << endl;
    sort(all(ans));
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}