#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S; cin >> S;
    int N = sz(S);
    bool rem[N]; 
    int cnt[N];
    vector<char> st; st.pb('a' - 1);
    char ld = 'a' - 1;
    int cur = N-2;
    rem[N-1] = true; cnt[N-1] = 1;
    while (cur >= 0) {
        if (S[cur] == S[cur+1]) {
            if (!rem[cur+1]) {
                st.pb(S[cur+1]);
                if (st[sz(st) - 2] != st[sz(st) - 1]) ld = st[sz(st) - 2];
            }
            rem[cur] = rem[cur+1];
            cnt[cur] = cnt[cur+1] + 1;
        } else {
            if (!rem[cur+1] || cnt[cur+1] % 2) {
                st.pb(S[cur+1]);
                if (st[sz(st) - 2] != st[sz(st) - 1]) ld = st[sz(st) - 2];

            }
            if (S[cur] > st[sz(st) - 1] || (S[cur] == st[sz(st) - 1] && S[cur] > ld)) {
                rem[cur] = true;
            } else {
                rem[cur] = false;
            }
            cnt[cur] = 1;
        }
        cur--;
    }

    if (!rem[0] || cnt[0] % 2) {
        st.pb(S[0]);
    }

    F0R(i, N) {
        cout << sz(st)-1 << " ";
        if (sz(st) > 11) {
            F0R(i, 5) {
                cout << st[sz(st) - i - 1];
            }
            cout << "..." << st[2] << st[1] << nl;
        } else {
            FORd(i, 1, sz(st)) {
                cout << st[i];
            }
            cout << nl;
        }
        if (rem[i]) {
            if (cnt[i] % 2) {
                st.pop_back();
            } else {
                st.pb(S[i]);
            }
        } else {
            st.pop_back();
        }
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343