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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        bool bla[N*M]; F0R(i, N) F0R(j, M) {
            char C; cin >> C; bla[i*M+j] = C == '0';
        }
        int nxt[N*M];
        F0R(i, N) {
            F0R(j, M) {
                char C; cin >> C;
                pi X;
                if (C == 'U') {
                    X = {i-1, j};
                } else if (C == 'R') {
                    X = {i, j+1};
                } else if (C == 'D') {
                    X = {i+1, j};
                } else {
                    X = {i, j-1};
                }
                nxt[i*M+j] = X.f*M + X.s;
            }
        }

        N *= M;
        int cyc[N];
        int val[N];
        F0R(i, N) {
            cyc[i] = -1; val[i] = -1;
        }
        bool vis[N]; F0R(i, N) vis[i] = false;
        bool root[N]; F0R(i, N) root[i] = false;
        int cnt[N]; F0R(i, N) cnt[i] = 0;
        bool in[N]; F0R(i, N) in[i] = false;
        
        F0R(r, N) {
            set<int> cur;
            if (vis[r]) continue;
            int X = r;
            cur.ins(X);
            vis[X] = true;
            X = nxt[X];
            while (!vis[X]) {
                vis[X] = true; cur.ins(X); X = nxt[X]; 
            }
            if (cur.count(X) && !in[X]) {
                cyc[X] = X; val[X] = 0; root[X] = true;
            }
            for (auto it = cur.find(X); it != cur.end(); it++) {
                in[*it] = true;
            }
        }

        F0R(r, N) {
            if (root[r]) {
                int X = r;
                X = nxt[X];
                cnt[r] = 1;
                while (X != r) {
                    X = nxt[X];
                    cnt[r]++;
                }
            }
        }

        F0R(r, N) {
            if (cyc[r] != -1) continue;
            stack<int> sta;
            sta.push(r);
            int X = nxt[r];
            while (cyc[X] == -1) {
                sta.push(X); X = nxt[X];
            }
            int cy = cyc[X];
            int va = val[X];
            while (!sta.empty()) {
                int cur = sta.top(); sta.pop();
                va++; va %= cnt[cy];
                cyc[cur] = cy; val[cur] = va;
            }
        }
        set<pi> found, found2;
        F0R(i, N) {
            if (bla[i]) {
                found.ins({cyc[i], val[i]});
            }
            found2.ins({cyc[i], val[i]});
        }
        cout << sz(found2) << " " << sz(found) << nl;

//        F0R(i, 9) {
//            cout << cyc[i] << " " << val[i] << " " << nxt[i] << nl;
//        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343