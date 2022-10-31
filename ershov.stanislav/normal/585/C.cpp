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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

ll a, b;
vector<pair<int, ll> > ans;

int swaped = 0;

void gcdExt() {
    if (a == b) {
        return;
    }
    if (a < b) {
        swap(a, b);
        swaped ^= 1;

        gcdExt();
        return;
    }
    ll k = a / b;
    if (b * k == a) {
        k--;
    }
    a -= b * k;
    swap(a, b);
    if (k > 0) {
        ans.eb(swaped, k);
    }
    swaped ^= 1;
    gcdExt();
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> a >> b;
    gcdExt();
    if (a > 1) {
        cout << "Impossible" << endl;
    } else {
        vector<pair<int, ll> > ans2;
        for (auto i : ans) {
            if (sz(ans2) == 0 || ans2.back().fs != i.fs) {
                ans2.pb(i);
            } else {
                ans2.back().sc += i.sc;
            }
        }
        for (int i = 0; i < sz(ans2); i++) {
            cout << ans2[i].sc << (char) ('A' + ans2[i].fs);
        }
        cout << endl;
    }
    return 0;
}