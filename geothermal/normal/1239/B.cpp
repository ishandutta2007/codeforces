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
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
int value(string S) {
    int lo = 0, cnt = 0;
    int cur = 0;
    F0R(i, sz(S)) {
        if (S[i] == '(') {
            cur++;
        } else cur--;
        if (ckmin(lo, cur)) {
            cnt = 0;
        }
        if (cur == lo) cnt++;
    }
    return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N;
    string S; cin >> S;

    int cnt = 0; F0R(i, N) if (S[i] == '(') cnt++;
    if (cnt * 2 != N) {
        cout << 0 << nl;
        cout << "1 1" << nl; return 0;
    }

    int lo = 0;
    int fLo = N+1, hLo = -1;
    int cur = 0;
    F0R(i, N) {
        if (S[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        ckmin(lo, cur);
    }
    cur = 0;
    F0R(i, N) {
        if (S[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < lo+2) {
            ckmin(fLo, i);
            ckmax(hLo, i);
        }
    }

    cur = 0;
    int best = 0, L = 0, R = 0;
    cnt = 0 ;
    int sta = 0;
    F0R(i, N) {
        if (S[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < lo+2) {
            if (ckmax(best, cnt)) {
                L = sta;
                R = i;
            }
            sta = i+1;
            cnt = 0;
        } 
        if (cur == lo+2) {
            cnt++;
        }
    }

    swap(S[L], S[R]);
    int ans = value(S);
    swap(S[L], S[R]);
    int bL = L, bR = R;
    if (hLo < N-1) {
        swap(S[fLo], S[hLo+1]);
        if (value(S) > ans) {
            ans = value(S);
            bL = fLo;
            bR = hLo+1;
        }
        swap(S[fLo], S[hLo+1]);
    }

    cur = 0;
    best = 0, L = 0, R = 0;
    cnt = 0 ;
    sta = 0;
    F0R(i, N) {
        if (S[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < lo+1) {
            if (ckmax(best, cnt)) {
                L = sta;
                R = i;
            }
            sta = i+1;
            cnt = 0;
        } 
        if (cur == lo+1) {
            cnt++;
        }
    }

    swap(S[L], S[R]);
    if (ckmax(ans, value(S))) {
        bL = L; bR = R;
    }
    swap(S[L], S[R]);


    cur = 0;
    fLo = N+1, hLo = -1;
    F0R(i, N) {
        if (S[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        if (cur < lo+1) {
            ckmin(fLo, i);
            ckmax(hLo, i);
        }
    }
    
    if (hLo < N-1) {
        swap(S[fLo], S[hLo+1]);
        if (value(S) > ans) {
            ans = value(S);
            bL = fLo;
            bR = hLo+1;
        }
        swap(S[fLo], S[hLo+1]);

    }

    cout << ans << nl;
    cout << bL+1 << " " << bR+1 << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343