#include <bits/stdc++.h>
using namespace std;

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

ll seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

const ll dr[4] = {0, 0, 1, -1};
const ll dc[4] = {-1, 1, 0, 0};

ll gv(char c) {
	if (c == 'L') return 0;
	if (c == 'R') return 1;
	if (c == 'D') return 2;
	return 3;
}

bool valid(ll r, ll c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	ll mat[n][m];
		
	for (ll i = 0; i < n; i++) {
		cin >> s;
		for (ll j = 0; j < m; j++) {
			if (s[j] == '.') mat[i][j] = -1;
			else mat[i][j] = gv(s[j]);
		}
	}
	
	pair<ll, ll> nxt[n][m][4];
	
	ll v = -1, cv = 0;
	for (ll sr = 0; sr < n; sr++) {
		for (ll sc = 0; sc < m; sc++) {
			if (mat[sr][sc] == -1) continue;
			
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < m; j++) {
					for (ll d = 0; d < 4; d++) {
						ll ni = i + dr[d], nj = j + dc[d];
						nxt[i][j][d] = make_pair(ni, nj);
					}
				}
			}
			
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < m; j++) {
					if (mat[i][j] == -1) {
						pair<ll, ll> l = nxt[i][j][0], r = nxt[i][j][1];
						if (valid(l.f, l.s)) nxt[l.f][l.s][1] = r;
						if (valid(r.f, r.s)) nxt[r.f][r.s][0] = l;
						
						pair<ll, ll> d = nxt[i][j][2], u = nxt[i][j][3];
						if (valid(d.f, d.s)) nxt[d.f][d.s][3] = u;
						if (valid(u.f, u.s)) nxt[u.f][u.s][2] = d;
					}
				}
			}
			
			pair<ll, ll> pos = make_pair(sr, sc);
			ll cnt = 0;
			while (valid(pos.f, pos.s)) {
				pair<ll, ll> l = nxt[pos.f][pos.s][0], r = nxt[pos.f][pos.s][1];
				if (valid(l.f, l.s)) nxt[l.f][l.s][1] = r;
				if (valid(r.f, r.s)) nxt[r.f][r.s][0] = l;
				
				pair<ll, ll> d = nxt[pos.f][pos.s][2], u = nxt[pos.f][pos.s][3];
				if (valid(d.f, d.s)) nxt[d.f][d.s][3] = u;
				if (valid(u.f, u.s)) nxt[u.f][u.s][2] = d;
				
				pos = nxt[pos.f][pos.s][mat[pos.f][pos.s]];
				++cnt;
			}
			if (cnt > v) {
				v = cnt;
				cv = 1;
			} else if (cnt == v) ++cv;
		}
	}
	
	cout << v << " " << cv << '\n';
}

// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("dining");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}