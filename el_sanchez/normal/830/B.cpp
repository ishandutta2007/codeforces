#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define forn(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
typedef vector<int> vi;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100111;

struct Fen {
    int t[N];
    void add(int p, int v) {
        for (; p < N; p |= p + 1)
            t[p] += v;
    }
    int sum(int p) {
        int s = 0;
        for (--p; p >= 0; p = (p&(p+1))-1)
            s += t[p];
        return s;
    }
    int sum(int l, int r) {
        return sum(r + 1) - sum(l);
    }
} fen;

ll ans = 0;

int main() {
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    static vector<int> poss[N];
    for (int i = 0; i < n; ++i) {
        fen.add(i, 1);
        int a;
        scanf("%d", &a);
        poss[a].push_back(i);
    }

    int cur = 0;
    auto proc = [&](int x) {
        if (cur <= x) {
            ans += fen.sum(cur, x);
        } else {
            ans += fen.sum(cur, n - 1);
            ans += fen.sum(0, x);
        }
        fen.add(x, -1);
        cur = x;
    };
    for (int i = 0; i < N; ++i) {
        auto const& arr = poss[i];
        if (arr.empty())
            continue;
        int j = lower_bound(all(arr), cur) - arr.begin();
        if (j == sz(arr))
            j = 0;
        for (int k = j; k < sz(arr); ++k)
            proc(arr[k]);
        for (int k = 0; k < j; ++k)
            proc(arr[k]);
    }

    cout << ans << "\n";

    return 0;
}