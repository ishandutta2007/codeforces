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
const int MX = 300001; //check the limits, dummy
 
struct AhoCorasick {
    static const int K = 26;

    struct Vertex {
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        ll value = -1;
        multiset<ll> nums;
        ll num;

        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
            nums.ins(-1);
            num = -1;
        }
    };

    vector<Vertex> t;

    void init() {
        Vertex v; t.pb(v);
    }



    int add_string(string const& s, int count) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        update(v, -1, 0);

        return v;
    }
    void update(int p, int o, int n) {

        if (o != -1) t[p].nums.erase(t[p].nums.find(o));
        t[p].nums.ins(n);
        t[p].num = *t[p].nums.rbegin();
    }


    ll getAns(string S) {
        int cur = 0;
        ll ans = -1;
        trav(a, S) {
            cur = go(cur, a);
            ckmax(ans, t[cur].num);
        }
        return ans;
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    AhoCorasick ac[MX];
    vi pos;
    F0R(i, MX) ac[i].init();
    set<int> lens;
    int L[N];
    F0R(i, N) {
        string S; cin >> S;
        lens.ins(sz(S));
        L[i] = sz(S);
        pos.pb(ac[sz(S)].add_string(S, 0));
    }
    int val[N]; F0R(i, N) val[i] = 0;
    while(M--) {
        int T; cin >> T;
        if (T == 1) {
            int i, x; cin >> i >> x; i--;
            ac[L[i]].update(pos[i], val[i], x);
            val[i] = x;
        } else {
            string S; cin >> S;
            ll ans = -1;
            trav(a, lens) {
                if (a > sz(S)) break;
                ckmax(ans, ac[a].getAns(S));
            }
            cout << ans << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343