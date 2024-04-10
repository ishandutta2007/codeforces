#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

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

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;
int cntA, cntC, cntG, cntT;

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
//    cout << s;
    for (int i = 0; i < len(s); i++) {
        if (s[i] == 'A') {
            cntA++;
        } else if (s[i] == 'C') {
            cntC++;
        } else if (s[i] == 'G') {
            cntG++;
        } else if (s[i] == 'T') {
            cntT++;
        }
    }
//    cout << cntT;
    int mx = max(cntA, max(cntC, max(cntG, cntT)));
    int l = 0;
    if (cntA == mx) {
        l++;
    }
    if (cntC == mx) {
        l++;
    }
    if (cntG == mx) {
        l++;
    }
    if (cntT == mx) {
        l++;
    }
    ll ans = 1;
    for (int i = 0; i < len(s); i++) {
        ans *= l;
        ans %= (int)(1e9 + 7);
    }
    cout << ans << endl;
    return 0;
}