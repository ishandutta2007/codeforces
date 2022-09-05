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
 
struct AhoCorasick {
    static const int K = 11;

    struct Vertex {
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        ll value = -1;
        ll num = 0;

        Vertex(int p=-1, char ch='0'+10) : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };

    vector<Vertex> t;

    void init() {
        Vertex v; t.pb(v);
    }



    void add_string(string const& s, int count) {
        int v = 0;
        for (char ch : s) {
            int c = ch - '0';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].num = count;
    }

    ll dfs(int v) {
        if (t[v].value != -1) {
            return t[v].value;
        }
        ll ans = t[v].num;
        ans += dfs(get_link(v)); // is this right?
        return t[v].value = ans;
    }

    void compute() {
        t[0].value = 0;
        FOR(i, 1, sz(t)) {
            dfs(i);
        }
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
        int c = ch - '0';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }
};
AhoCorasick ac;
string cur = "";

void get(int S, int K) {
    if (S == K) {
        F0R(i, sz(cur)) {
            FOR(j, i+1, sz(cur)) {
                int sum = 0;
                FOR(k, i, j+1) {
                    sum += cur[k] - '0';
                }
                if (K % sum == 0 && K != sum) return;
            }
        }
        ac.add_string(cur, 1);
        return;
    }
    FOR(i, 1, 10) {
        if ((K % i == 0 && i != K) || S+i > K) continue;
        cur += '0' + i;
        get(S+i, K);
        cur.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    string S; int K; cin >> S >> K;
    ac.init();
    get(0, K);

    int M = sz(ac.t);

    int N = sz(S);

    int dp[N+1][M]; F0R(i, N+1) F0R(j, M) dp[i][j] = N+1;

    dp[0][0] = 0;
    F0R(i, N) {
        F0R(j, M) {
            ckmin(dp[i+1][j], dp[i][j] + 1);
            int v = ac.go(j, S[i]);
            if (ac.t[v].num > 0) continue;
            ckmin(dp[i+1][v], dp[i][j]);
        }
    }

    int ans = N+1; 
    F0R(i, M) ckmin(ans, dp[N][i]);


    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343