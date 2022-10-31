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

const int N = 1100;
const int MOD = 1e9 + 7;

int n;
ll k;

ll dp[55];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 55; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cin >> n >> k;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (i < n - 1 && k > dp[n - i - 1]) {
            k -= dp[n - i - 1];
            i++;
        }
        int lst = (int) ans.size();
        for (int j = ans.size(); j < i; j++) {
            ans.pb(j + 2);
        }
        ans.pb(lst + 1);
    }
    for (auto i : ans) {
        printf("%d ", i);
    }
    return 0;
}