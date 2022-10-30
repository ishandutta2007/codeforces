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

using namespace std;

const int N = 200200;

int n, a[N], m, b[2*N];
int cnt[N];
vector<ll> ans;

void check(int cur, bool left) {
    vector<int> p;
    ll len = 0;
    for (int i = 0; i < m; i++) {
        p.pb(cur);
        if (left && cur == 1) {
            left = false;
        }
        if (!left && cur == n) {
            left = true;
        }
        if (i < m - 1) {
            len += abs(a[cur] - a[cur + (left ? -1 : 1)]);
        }
        cur += left ? -1 : 1;
    }
    sort(all(p));
//    for (int i = 0; i < m; i++) {
//        cout << p[i] << ' ';
//    }
//    cout << endl;
//    cout << len << endl;
    bool flag = true;
    for (int i = 0; i < m; i++) {
        if (b[i + 1] != p[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        ans.pb(len);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        cnt[b[i]]++;
    }
    check(1, true);
    check(1, false);
    check(n, true);
    check(n, false);
    for (int i = 1; i < n; i++) {
        if (cnt[i] != cnt[i + 1] || cnt[i - 1] != cnt[i]) {
            check(i, false);
            check(i, true);
        }
    }
    sort(all(ans));
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << endl;
//    }
    if (ans[0] != ans.back()) {
        cout << -1 << endl;
    } else {
        cout << ans[0] << endl;
    }
    return 0;
}