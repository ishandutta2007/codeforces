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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

int mult(ll a, ll b) {
    return a * b % MOD;
}

const int maxn = 5e6 + 100;
int n, h, w;
char s[maxn];
int ph[maxn], pw[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d%d %s", &n, &h, &w, s);
    for (int i = 0; i < n; i++) {
        s[n + i] = s[i];
    }
    int xmn = 0, xmx = 0, ymn = 0, ymx = 0;
    int curx = 0, cury = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'L') {
            curx--;
        } else if (s[i] == 'R') {
            curx++;
        } else if (s[i] == 'U') {
            cury++;
        } else {
            cury--;
        }
        if (curx < xmn) {
            xmn = curx;
            pw[i]++;
        }
        if (curx > xmx) {
            xmx = curx;
            pw[i]++;
        }
        if (cury < ymn) {
            ymn = cury;
            ph[i]++;
        }
        if (cury > ymx) {
            ymx = cury;
            ph[i]++;
        }
    }
    int curh = 1, curw = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ph[i]) {
            curh++;
            ans = add(ans, mult(i + 1, w + 1 - curw));
        }
        if (pw[i]) {
            curw++;
            ans = add(ans, mult(i + 1, h + 1 - curh));
        }
        if (h < curh || w < curw) {
            break;
        }
    }
    vector<int> changeh, changew;
    for (int i = n; i < 2 * n; i++) {
        if (pw[i]) {
            changew.pb(i - n);
        }
        if (ph[i]) {
            changeh.pb(i - n);
        }
    }
    for (int curt2 = 1; curt2 < 3e6; curt2++) {
        int i = 0, j = 0;
        if (w < curw || h < curh) {
            break;
        }
        for (; i < sz(changeh) && j < sz(changew); ) {
            if (changeh[i] < changew[j]) {
                if (curh > h || curw > w) {
                    break;
                }
                ll curt = (ll) curt2 * n + changeh[i];
                curh++;
                ans = add(ans, mult(curt + 1, w + 1 - curw));
                i++;
            } else {
                if (curh > h || curw > w) {
                    break;
                }
                ll curt = (ll) curt2 * n + changew[j];
                curw++;
                ans = add(ans, mult(curt + 1, h + 1 - curh));
                j++;
            }
        }
        for (; i < sz(changeh); i++) {
            if (curh > h || curw > w) {
                break;
            }
            ll curt = (ll) curt2 * n + changeh[i];
            curh++;
            ans = add(ans, mult(curt + 1, w + 1 - curw));
        }
        for (; j < sz(changew); j++) {
            if (curh > h || curw > w) {
                break;
            }
            ll curt = (ll) curt2 * n + changew[j];
            curw++;
            ans = add(ans, mult(curt + 1, h + 1 - curh));
        }
        if (curt2 == (int) 3e6 - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}