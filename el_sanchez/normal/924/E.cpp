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

int main() {
    ios::sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> w0, w1;
    int s = 0;
    vector<int> qqq(n);
    for (int &x : qqq) {
        cin >> x;
        s += x;
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (b)
            w1.push_back(qqq[i]);
        else
            w0.push_back(qqq[i]);
    }

    vector<int> d0(s+1, 0);
    d0[s] = 1;
    for (int w : w0)
        for (int i = 0; i + w <= s; ++i)
            d0[i] |= d0[i+w];

    vector<int> d1(s+1, -IINF);
    for (int i = 0; i <= s; ++i)
        if (d0[i])
            d1[i] = 0;

    sort(all(w1), greater<int>());
    for (int w : w1)
        for (int i = 0; i + w <= s; ++i)
            d1[i] = max(d1[i], d1[i + w] + (l <= i && i <= r));

    cout << *max_element(all(d1)) << "\n";

    return 0;
}