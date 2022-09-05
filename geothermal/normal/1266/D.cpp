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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    ll ind[N], out[N]; F0R(i, N) ind[i] = 0, out[i] = 0;
    F0R(i, M) {
        int A, B; ll C; cin >> A >> B >> C;
        A--;
        B--;
        ind[B]+=C;
        out[A]+=C;
    }
    vi data;
    vector<vpl> graph(N);
    map<ll, ll> owes, needs;
    F0R(i, N) {
        if (ind[i] > out[i]) {
            needs.insert({i, ind[i]-out[i]});
        } else if (out[i] > ind[i]) {
            owes.insert({i, out[i]-ind[i]});
        }
/*        while (sz(ins[p]) > 0 && sz(outs[p]) > 0) {
            pl A = *(ins[p].begin());
            pl B = *(outs[p].begin());
            ins[p].erase(ins[p].begin());
            outs[p].erase(outs[p].begin());
            outs[A.f].erase(p);
            ins[B.f].erase(p);
            ll val = min(A.s, B.s);
            A.s -= val; B.s -= val;
            if (A.s > 0) {
                ins[p].insert(A);
                outs[A.f].insert({p, A.s});
            }
            if (B.s > 0) {
                outs[p].insert(B);
                ins[B.f].insert({p, B.s});
            }
            outs[A.f][B.f]+=val;
            ins[B.f][A.f]+=val;
        }*/
/*        while (sz(outs[i]) > 0) {
            pl A = *(outs[i].begin());
            int p = A.f;
            outs[i].erase(p);
            if (sz(outs[p]) == 0) {
                finalDebts.pb({i+1, p+1, A.s});
                continue;
            }
            pl B = *(outs[p].begin());
            outs[p].erase(outs[p].begin());
            ll val = min(A.s, B.s);
            A.s -= val; B.s -= val;
            if (A.s > 0) {
                outs[i].insert({p, A.s});
            }
            if (B.s > 0) {
                outs[p].insert(B);
            }
            if(B.f != i) outs[i][B.f]+=val;
        }*/
    }

    vector<vl> finalDebts;
    while(sz(owes) > 0 && sz(needs) > 0) {
        pl A = *(owes.begin());
        pl B = *(needs.begin());
        ll val = min(A.s, B.s);
        finalDebts.pb({A.f+1, B.f+1, val});
        owes.begin()->s-=val;
        needs.begin()->s-=val;
        if (owes.begin()->s == 0) owes.erase(owes.begin());
        if (needs.begin()->s == 0) needs.erase(needs.begin());
    }
    cout << sz(finalDebts) << endl;
    F0R(i, sz(finalDebts)) {
        cout << finalDebts[i][0] << " " << finalDebts[i][1] << " " << finalDebts[i][2] << endl;
    }
/*    int ans = 0;
    F0R(i, N) ans += sz(outs[i]);
    cout << ans << endl;
    F0R(i, N) {
        for (auto it = outs[i].begin(); it != outs[i].end(); it++) {
            cout << i+1 << " " << it->f+1 << " " << it->s << endl;
        }
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343