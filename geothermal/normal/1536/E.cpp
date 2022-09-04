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

struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;


int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void solve() {

    int N, M; cin >> N >> M;
    bool ok[N][M];
    bool found = false;
    int cnt = 0;
    F0R(i, N) {
        F0R(j, M) {
            char C; cin >> C; ok[i][j] = C != '0';
            if (!ok[i][j]) found = true;
            if (ok[i][j]) cnt++;
        }
    }
    mi ans = pow(mi(2), cnt); if (!found) ans--;
    cout << ans << nl;

    /*if (!found) {
        mi ans = 1;
        F0R(i, N) {
            F0R(j, M) {
                int dist = max(i, N-1-i) + max(j, M-1-j);
                ans += pow(mi(2), dist) - 1;
            }
        }
        cout << ans << nl; return;
    }

    int dist[N][M], comp[N][M];
    queue<pi> q;
    F0R(i, N) {
        F0R(j, M) {
            comp[i][j] = -1;
            dist[i][j] = 100000;
            if (!ok[i][j]) { 
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s; q.pop();
        F0R(i, 4) {
            int nx = x+dx[i], ny = y + dy[i];
            if (valid(nx, ny, N, M) && ckmin(dist[nx][ny], dist[x][y]+1)) {
                q.push({nx, ny});
            }
        }
    }
    int nxt = 0;
    F0R(ri, N) {
        F0R(rj, M) {
            if (!ok[ri][rj] || comp[ri][rj] != -1) continue;
            q.push({ri, rj});
            comp[ri][rj] = nxt;
            while (!q.empty()) {
                int x = q.front().f, y = q.front().s; q.pop();
                F0R(i, 4) {
                    int nx = x+dx[i], ny = y + dy[i];
                    if (valid(nx, ny, N, M) && ok[nx][ny] && comp[nx][ny] = -1) {
                        comp[nx][ny] = nxt;
                        q.push({nx, ny});
                    }
                }
            }
            nxt++;
        }
    }

    int cap[nxt];  F0R(i, nxt) cap[i] = 0;
    F0R(i, N) F0R(j, M) if (comp[i][j] != -1) ckmax(cap[nxt], dist[i][j]);

    mi ans = 1;
    F0R(i, nxt) {
        ans *= pow(
    }*/


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