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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 100001; 

string G = "haha";

ll get(string S) {
    ll ans = 0;
    F0R(i, sz(S) - 3) {
        F0R(j, 4) {
            if (S[i+j] != G[j]) goto done;
        }
        ans++;
        done:
        ;
    }
    return ans;

}

struct Var {
    ll num;
    string pre, suf;
    Var() {
        num = 0; pre = ""; suf = "";
    }
    Var(string S) {
        num = get(S);
        pre = S.substr(0, 3);
        suf = S.substr(max(0, sz(S)-3), 3);
    }
};

Var merge(Var A, Var B) {
    Var res("");
    res.num = A.num + B.num + get(A.suf+B.pre);
    res.pre = A.pre;
    F0R(i, min(3-sz(A.pre), sz(B.pre))) res.pre += B.pre[i];
    res.suf = B.suf;
    reverse(all(res.suf));
    F0R(i, min(3-sz(B.suf), sz(A.suf))) res.suf += A.suf[sz(A.suf)-1-i];
    reverse(all(res.suf));
    return res;
}

void solve() {

    int N; cin >> N;
    map<string, Var> state;
    ll lst = 0;
    F0R(i, N) {
        string vn; cin >> vn;
        string T; cin >> T;
        if (T[0] == ':') {
            string S; cin >> S;
            state[vn] = Var(S);
        } else {
            string X, Y, P; cin >> X >> P >> Y;
            state[vn] = merge(state[X], state[Y]);
        }
        lst = state[vn].num;
    }
    cout << lst << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}