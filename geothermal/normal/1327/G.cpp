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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
struct AhoCorasick {
    static const int K = 14;

    struct Vertex {
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        ll value = -1;
        ll num = 0;

        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
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
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].num += count;
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
                t[v].link = go(get_link(t[v].p), t[v].pch-'a');
        }
        return t[v].link;
    }

    int go(int v, int c) {
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
        }
        return t[v].go[c];
    }
};


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int K; cin >> K;
    AhoCorasick at; at.init();
    F0R(i, K) {
        string S; ll C; cin >> S >> C;
        at.add_string(S, C);
    }

    string S; cin >> S;
    vi pos;
    pos.pb(0);
    F0R(i, sz(S)) if (S[i] == '?') pos.pb(i+1);
    pos.pb(sz(S) + 1);
    int V = sz(at.t);
    at.compute();

    pl trans[sz(pos)-1][V];
    F0R(s, sz(pos) - 1) {
        F0R(v, V) {
            pl res = {v, 0};
            FOR(i, pos[s], pos[s+1] - 1) {
                res.f = at.go(res.f, S[i] - 'a');
                res.s += at.t[res.f].value;
            }
            trans[s][v] = res;
        }
    }
    int cnt = sz(pos) - 2;

/*    F0R(i, sz(pos) - 1) {
        F0R(j, V) {
            cout << i << " " << j << " " << trans[i][j].f << " " << trans[i][j].s << endl;
        }
    }*/

    ll dp[1 << 14][V];
    F0R(i, 1 << 14) F0R(j, V) dp[i][j] = -1000000000000000;
    dp[0][0] = 0;
    ll ans = -1000000000000000;
    F0R(mask, 1 << 14) {
        F0R(v, V) {
            int C = 0; F0R(i, 14) if (mask & (1 << i)) C++;
            if (C >= cnt) continue;
            ll newPos = trans[C][v].f;
            ll newSum = trans[C][v].s + dp[mask][v];
            F0R(i, 14) {
                if (mask & (1 << i)) continue;
                ll np = at.go(newPos, i);
                ll ns = newSum + at.t[np].value;
                dp[mask + (1 << i)][np] = max(dp[mask + (1 << i)][np], ns);
            }
        }
    }
    F0R(mask, 1 << 14) {
        F0R(v, V) {
//            if (mask < 8) cout << mask << " " << v << " " << dp[mask][v] << endl;
            int C = 0; F0R(i, 14) if (mask & (1 << i)) C++;
            if (C != cnt) continue;
            ll newPos = trans[C][v].f;
            ll newSum = trans[C][v].s + dp[mask][v];
            ans = max(ans, newSum);
        }
    }

    cout << ans << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343