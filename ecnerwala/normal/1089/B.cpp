#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000009;

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll euclid(ll a, ll b, ll &x, ll &y) {
	if(b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}
ll modpow(ll a, ll e){
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}
ll invert(ll a) {
	a %= mod;
	assert(a != 0);
	return modpow(a, mod-2);
}


int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;
	
	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n)
			if (abs(A[j][k] % mod) > abs(A[r][c] % mod))
				r = j, c = k;
		if (A[r][c] % mod == 0) return i;
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = A[i][i];
		rep(j,i+1,n) {
			ll f = A[j][i] * invert(v) % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f * A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f * tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = (A[i][j] * invert(v)) % mod;
		rep(j,0,n) tmp[i][j] = (tmp[i][j] * invert(v)) % mod;
		A[i][i] = 1;
	}
	
	for (int i = n-1; i > 0; i--) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v * tmp[i][k]) % mod;
	}
	
	rep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];
	return n;
}

vector<pii> generalMatching(int N, vector<pii>& ed) {
	vector<vector<ll>> mat(N, vector<ll>(N)), A;
	trav(pa, ed) {
		int a = pa.first, b = pa.second, r = rand() % mod;
		mat[a][b] = r, mat[b][a] = (mod - r) % mod;		
	}
	
	int r = matInv(A = mat), M = 2*N - r, fi, fj;
	assert(r % 2 == 0);
	
	if (M != N) do {
		mat.resize(M, vector<ll>(M));
		rep(i,0,N) {
			mat[i].resize(M);
			rep(j,N,M) {
				int r = rand() % mod;
				mat[i][j] = r, mat[j][i] = (mod - r) % mod;
			}
		}
	} while (matInv(A = mat) != M);
	
	vi has(M, 1); vector<pii> ret;
	rep(it,0,M/2) {
		rep(i,0,M) if (has[i])
			rep(j,i+1,M) if (A[i][j] && mat[i][j]) {
				fi = i; fj = j; goto done;
		} assert(0); done:
		if (fj < N) ret.emplace_back(fi, fj);
		has[fi] = has[fj] = 0;
		rep(sw,0,2) {
			ll a = modpow(A[fi][fj], mod-2);
			rep(i,0,M) if (has[i] && A[i][fj]) {
				ll b = A[i][fj] * a % mod;
				rep(j,0,M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
			}
			swap(fi, fj);
		}
	}
	return ret;
}

void solve(){
	int n, m;
	cin >> n >> m;
	int N = 2 * n + m;
	vector<pair<int,int> > edges;
	for(int i = 0; i < n; i++){
		edges.push_back({i, i+n});
		string f;
		cin >> f;
		for(int j = 0; j < m; j++){
			if(f[j] == '1'){
				edges.push_back({i, j+n+n});
				edges.push_back({i+n, j+n+n});
			}
		}
	}
	int ans = generalMatching(N, edges).size();
	ans -= n;
	cout << ans << '\n';
}

void testm(){
	vector<vector<ll> > A = {{1, 1, 0}, {0, 2, 0}, {0, 0, 3}};
	matInv(A);
	for(auto x : A){
		for(auto y : x){
			cout << y << " ";
		}
	}
	cout << '\n';
	exit(0);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//testm();
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}