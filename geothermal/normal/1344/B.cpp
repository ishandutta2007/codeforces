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
	
    int N, M; cin >> N >> M;
    bool C[N][M];
    F0R(i, N) {
        F0R(j, M) {
            char c; cin >> c;
            C[i][j] = c == '#';
        }
    }

    int lR[N], hR[N], lC[M], hC[M];
    F0R(i, N) {
        lR[i] = M+1; hR[i] = -1;
    }
    F0R(i, M) {
        lC[i] = N+1; hC[i] = -1;
    }
    F0R(i, N) {
        F0R(j, M) {
            if (C[i][j]) {
                lR[i] = min(lR[i], j);
                lC[j] = min(lC[j], i);
                hR[i] = max(hR[i], j);
                hC[j] = max(hC[j], i);
/*                if (j == 4) cout << i << " " << j << " " << " " << lR[i] << " " << hR[i] << " " << lC[j] << " " << hC[j] << endl;
                cout << lC[4] << " " << hC[4] << " " << lC[j] << " " << hC[j] << endl;
                if (lC[4] == 5) {
                    cout << "BAD " << i << " " << j << endl; 
                }*/
            }
        }
    }

    //cout << lC[4] << " " << hC[4] << endl;

    int eR = 0, eC = 0;
    F0R(i, N) {
        if (lR[i] > hR[i]){
            eR = 1; 
        }
    }
    F0R(i, M) if (lC[i] > hC[i]) {
        eC = 1; //cout << i << " " << lC[i] << " " << hC[i] << endl;
    }
	if (eR + eC == 1) {
        cout << -1 << nl; return 0;
    }
    F0R(i, N) {
        F0R(j, M) {
            if (!C[i][j]) {
                if ((lR[i] <= j && j <= hR[i]) || (lC[j] <= i && i <= hC[j])) {
                    cout << -1 << nl; return 0;
                }
            }
        }
    }

    int comp[N][M]; F0R(i, N) F0R(j, M) comp[i][j] = -1;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    int nc = 0;

    F0R(ri, N) {
        F0R(rj, M) {
            if (comp[ri][rj] != -1 || !C[ri][rj]) continue;
//            cout << ri << " " << rj << endl;
            comp[ri][rj] = nc;
            queue<pi> q; q.push({ri, rj});
            while (!q.empty()) {
                pi cur = q.front(); q.pop();
                int x = cur.f, y = cur.s;
                F0R(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (comp[nx][ny] != -1 || !C[nx][ny]) continue;
                    comp[nx][ny] = nc; q.push({nx, ny});
                }
            }
            nc++;
        }
    }
    cout << nc << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343