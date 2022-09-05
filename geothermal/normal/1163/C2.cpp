#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

bool equals(double a, double b) {
    return abs(a-b) <= 1e-8;
}

struct Compare {
    bool operator()(const pair<double, double>& lhs, const pair<double, double>& rhs) {
        if (lhs.first+1e8 < rhs.f) {
            return true;
        } else if (rhs.f+1e8 < lhs.f) {
            return false;
        }
        if (lhs.second+1e8 < rhs.s) {
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    map<ll, set<ll>> lines;

    ll N; cin >> N;
    int X[N], Y[N];
    F0R(i, N) {
        cin >> X[i] >> Y[i];
    }

    ll count = 0;

    F0R(i, N) {
        FOR(j, i+1, N) {
            double dy = Y[j] - Y[i]; double dx = X[j] - X[i]; double slope;
            if (dx == 0) {
                slope = 5000.1;
            } else {
                slope = dy / dx;
            }
            double inter = slope * X[i] * -1 + Y[i];
            if (slope == 5000.1) {
                inter = X[i];
            }


            slope += 1e-10; inter += 1e-10;
            ll bigSlope = (ll) floor((slope * 1e9));
            ll bigInter = (ll) floor((inter * 1e9));
            if (lines.count(bigSlope) == 0) {
                set<ll> data; data.insert(bigInter); lines.insert(mp(bigSlope, data));
                count++;
            } else {
                if (!lines[bigSlope].count(bigInter)) {
                    lines[bigSlope].insert(bigInter);
                    count++;
                }
            }
        }
    }

    ll ans = count*(count-1)/2;
    for (auto it = lines.begin(); it != lines.end(); it++) {
        ll count = it->s.size();
        ans -= count * (count-1) / 2;
    }
    cout << ans << endl;



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343