#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int INF = int(1e9);
const ll INFll = 1ll * INF * INF;
const int MOD = 1000000007;

bool comp2(pii a, pii b) {
    return ((a.F + a.S) < (b.F + b.S));
}

bool comp3(pii a, pii b) {
    return ((a.F - a.S) < (b.F - b.S));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, m;
    cin >> n >> m;
    int c;
    cin >> c;
    vector<pii> x(c);
    for (int i = 0; i < c; ++i)
        cin >> x[i].F >> x[i].S;
    int h;
    cin >> h;
    vi x1(h), y1(h);
    for (int i = 0; i < h; ++i)
        cin >> x1[i] >> y1[i];
    int ans1 = 2 * INF + 500, ans2;
    vector<pii> p;
    sort(x.begin(), x.end(), comp2);
    p.pb(x[0]);
    p.pb(x.back());
    sort(x.begin(), x.end(), comp3);
    p.pb(x[0]);
    p.pb(x.back());
    for (int i = 0; i < h; ++i) {
        int cur = 0;
        for (int j = 0; j < p.size(); ++j)
            cur = max(cur, abs(x1[i] - p[j].F) + abs(y1[i] - p[j].S));
        if (cur < ans1) {
            ans1 = cur;
            ans2 = i + 1;
        }
    }
    cout << ans1 << endl << ans2;
    return 0;
}