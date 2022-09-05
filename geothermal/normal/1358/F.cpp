#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
vl A, na;
void sim(vl &B, vl& res, ll K) {
    int N = sz(B);
    res[0] = B[0];
    FOR(i, 1, N) {
        ll hi = B[i-1];
        ll lo = B[i-1];
        
        res[i] = B[i] - ((hi + lo) * K) / 2;
        if (res[i] < A[i]) {
            res[0] = -1; return;
        }
    }
}

ll cntIts(vl &B, vl &res) {
    ll lo = 0, hi = 1;
    if (sz(B) == 2) hi = B[1] / B[0];
    while (lo < hi) {
        ll mid = (lo+hi+1)/2;
        sim(B, res, mid);
        if (res[0] >= 0) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

bool get(int N, vl B, bool add) {
    A = na;
    bool smol = true;
    string ans;
    ll total = 0;
    vl res(N); 
    ll MSMALL = 200000;
    ll cnt;
    bool lastRev = false;
    while (true) {
        cnt = cntIts(B, res);
        sim(B, res, cnt);
        if (res[0] != -1) B = res;
        total += cnt;
        if (total <= MSMALL) { 
            F0R(i, cnt) {
                ans += 'P';
            }
        } else {
            smol = false;
        }
        if (cnt == 0) {
            if (lastRev) {
                break;
            } else {
                ans += 'R';
                reverse(all(B)); reverse(all(A));
                lastRev = true;
            }
        } else {
            lastRev = false;
        }
    }
    F0R(i, N) {
        if (na[i] != B[i]) goto bad;
    }
    goto done;
    bad:
    ;

    reverse(all(B)); ans += 'R';
    F0R(i, N) {
        if (na[i] != B[i]) goto bad2;
    }
    done:
    ;
    if (smol) {
        cout << "SMALL" << nl;
        if (add) {
            ans += 'R';
        }
        cout << sz(ans) << nl;
        reverse(all(ans)); cout << ans << nl;
    } else {
        cout << "BIG" << nl;
        cout << total << nl;
    }

    return true;

    bad2:
    ;
    return false;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    F0R(i, N) {
        ll X; cin >> X; A.pb(X);
    }
    na = A;
    vl B(N); F0R(i, N) {
        cin >> B[i];
    }

    if (N == 1) {
        if (A[0] == B[0]) {
            cout << "SMALL\n0\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
        return 0;
    }

    if (get(N, B, false)) {
        return 0;
    } 
    reverse(all(na));
    if (get(N, B, true)) {
        return 0;
    }
    cout << "IMPOSSIBLE" << nl;

    return 0;

}