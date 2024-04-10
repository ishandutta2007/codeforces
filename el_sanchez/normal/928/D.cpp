#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

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
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 300179;

struct Node {
    bool have;
    int cnt;
    int e[26];
    Node() : have(0), cnt(0) {
        memset(e, -1, sizeof(e));
    }
} bor[N];
int bs = 1;

void borAdd(string const& s) {
    int v = 0;
    for (char cc : s) {
        int c = cc - 'a';
        int &nv = bor[v].e[c];
        if (nv == -1)
            nv = bs++;
        v = nv;
    }
    if (bor[v].have)
        return;
    bor[v].have = 1;
    v = 0;
    for (char cc : s) {
        ++bor[v].cnt;
        int c = cc - 'a';
        int &nv = bor[v].e[c];
        if (nv == -1)
            nv = bs++;
        v = nv;
    }
    ++bor[v].cnt;
}

int ans = 0;
void go(string const& s) {
    int v = 0;
    bool was = false;
    int i = 0;
    while (i < sz(s)) {
        if (v == -1) {
            ans += sz(s) - i;
            break;
        }
        int c = s[i] - 'a';
        if (!was && v != 0 && bor[v].cnt == 1) {
            was = true;
            int j = i;
            int v1 = v;
            bool ok = false;
            while (v1 != -1) {
                if (bor[v1].have) {
                    ok = 1;
                    break;
                }
                if (j == sz(s))
                    break;
                v1 = bor[v1].e[s[j] - 'a'];
                ++j;
            }
            if (i != j && ok) {
                ++ans;
                v = v1;
                i = j;
                continue;
            }
        }
        ++ans;
        v = bor[v].e[c];
        ++i;
    }
    borAdd(s);
}

int main() {
    ios::sync_with_stdio(false);

    string s;
    while (getline(cin, s)) {
        if (sz(s) == 0)
            continue;
        ++ans;
        int i = 0;
        while (i < sz(s)) {
            if (!('a' <= s[i] && s[i] <= 'z')) {
                ++i;
                ++ans;
                continue;
            }
            int j = i + 1;
            while (j < sz(s) && 'a' <= s[j] && s[j] <= 'z')
                ++j;
            go(s.substr(i, j - i));
            i = j;
        }
    }
    cout << ans << "\n";
    return 0;
}