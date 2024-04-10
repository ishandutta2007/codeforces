#include <bits/stdc++.h>
using namespace std;

#define fastio {\
    ios::sync_with_stdio(0);\
    cin.tie(0);\
}

#define file {\
    freopen("io\\in.txt", "r", stdin);\
    freopen("io\\out.txt", "w", stdout);\
    freopen("io\\err.txt", "w", stderr);\
}

#ifdef LOCAL
#define debug(args...) {\
    string _s(#args);\
    replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s);\
    istream_iterator<string> _it(_ss);\
    debug1(_it, args);\
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
void debug1(istream_iterator<string> it) {
    cerr << endl;
}
#pragma GCC diagnostic pop

template<class T, class... Args>
void debug1(istream_iterator<string> it, T a, Args... args) {
    cerr << '>' << *it << " = " << a << "; ";
    debug1(++it, args...);
}
#else
#define debug(args...)
#define cerr if (false) cerr
#endif

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < n; i++)
#define dotc()      int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

const int inf(0x3fffffff);
const int mod(1000000007);
const double pi(acos(-1.0));

signed main() {
    fastio;
#ifdef LOCAL
    file;
#endif

    int n;
    cin >> n;
    map<int, int> m, f;
    rep(i, n) {
        int x;
        cin >> x;
        m[x - 1] = i;
    }
    rep(i, n) {
        int x;
        cin >> x;
        f[(m[x - 1] - i + n) % n]++;
    }

    int mx = 0;
    for (auto& i : f) mx = max(mx, i.se);
    cout << mx;

    return 0;
}