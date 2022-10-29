#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> need(n);
    for (int i = 0; i < n; ++i)
        need[i] = a[i] + 1;
    for (int i = n - 1; i > 0; --i)
        need[i-1] = max(need[i-1], need[i] - 1);
    int cc = 0;
    vector<int> add(n, 0);
    for (int i = 0; i < n; ++i) {
        if (need[i] > cc) {
            ++cc;
            add[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (add[i]) {
            ans += cnt - a[i];
            ++cnt;
        } else {
            ans += cnt - a[i] - 1;
        }
    }
    cout << ans << "\n";


    return 0;
}