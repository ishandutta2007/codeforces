#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream> 
#include <string> 
#include <algorithm>   
#include <cassert>  
#include <cmath>  

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

#define FILE_NAME "a"

int T;
ll a, b, n;

bool read() {
    if (!(cin >> a >> b >> n)) {
        return 0;
    }
    return 1;
}

ll solve() {
    if (a < b) {
        swap(a, b);
    }
    ll ans = 0;
    while (a <= n) {
        b += a;
        ans++;
        swap(a, b);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    int T;
    cin >> T;
    while (read()) {
        ll ans = solve();
        cout << ans << '\n';
    }

    return 0;
}