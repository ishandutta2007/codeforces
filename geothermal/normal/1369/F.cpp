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

bool win(ll S, ll E) {
    if (E % 2) {
        return S % 2 == 0;
    }
    if (S*2 > E) {
        return S % 2 == 1;
    }
    E /= 2;
    if (S * 2 > E) {
        return true;
    }
    return win(S, E / 2);
}

bool lose(ll S, ll E) {
    if (S * 2 > E) {
        return true;
    }
    return win(S, E / 2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int T[N];

    F0R(i, N) {
        ll S, E; cin >> S >> E;
        int cur = 0;
        if (win(S, E)) cur+=2;
        if (lose(S, E)) cur++;
        T[i] = cur;
//        cout << T[i] << nl;
    }


    int ans = T[N-1];
    F0Rd(i, N-1) {
        int nxt = 0;
        int cur = T[i];
        if ((ans & 2) && (cur & 1)) {
            nxt+=2;
        } else if ((ans & 2) == 0 && (cur & 2)) {
            nxt+=2;
        }

        if ((ans&1) && (cur&1)) {
            nxt+=1;
        } else if ((ans&1)==0 && (cur & 2)) {
            nxt+=1;
        }
        ans = nxt;
    }

    cout << ans/2 << " " << ans%2 << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343