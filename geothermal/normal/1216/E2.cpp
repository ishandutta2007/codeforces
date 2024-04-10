#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll digsInBig(ll val) {
    ll cnt = 9;
    ll lo = 1;
    ll total = 0;
    F0R(i, 18) {
        ll hiOc = (val-lo+1);
        ll hiVal = lo + cnt - 1;
        hiVal = min(hiVal, val);
        ll loOc = (val - hiVal + 1);
        ll totalVals = (hiVal-lo+1);

        ll curSum = totalVals * (hiOc + loOc) / 2;
        total += curSum * (i+1);

        lo += cnt;
        if (lo > val) return total;
        cnt *= 10;
    }
    return total;
}

ll digsUpTo(ll val) {
    ll cnt = 9;
    ll lo = 1;
    ll total = 0;
    F0R(i, 18) {
        ll hiVal = lo + cnt - 1;
        hiVal = min(hiVal, val);
        total += (hiVal - lo + 1) * (i+1);

        lo += cnt;
        if (lo > val) return total;
        cnt *= 10;
    }
    total += 19;
    return total;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    //get digit i in 123456789101112131415...
    //count digits in some prefix to find the number it's a part of

    //count digits in 112123123412345123456...
    //go by digit counts
    int Q; cin >> Q;
    while(Q--) {
        ll N; cin >> N;
        ll lo = 1, hi = 500000000;
        F0R(i, 40) {
            ll mid = (lo+hi)/2;
            ll digs = digsInBig(mid);
            if (digs > N) {
                hi = mid;
            } else {
                lo = mid;
            }
            if (hi < lo) break;
        }
        ll index = min(lo, hi);
        if (digsInBig(index) < N) {
            index = max(lo, hi);
        }
        N -= digsInBig(index-1);
        lo = 1, hi = index;
        F0R(i, 40) {
            ll mid = (lo+hi)/2;
            ll digs = digsUpTo(mid);
            if (digs > N) {
                hi = mid;
            } else {
                lo = mid;
            }
            if (hi < lo) break;
        }
        ll index2 = min(lo, hi);
        if (digsUpTo(index2) < N) {
            index2 = max(lo, hi);
        }
        N -= digsUpTo(index2-1);
        vl digits;
//        cout << N << " " << index << " " << index2 << endl;
        while (index2 > 0) {
            digits.pb(index2%10); index2 /= 10;
        }
        reverse(all(digits));
        cout << digits[N-1] << endl;
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343