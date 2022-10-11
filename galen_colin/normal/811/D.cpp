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
const ll template_array_size = 1e6 + 9097;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

string mat[105];
pair<ll, ll> pos, cur = {0, 0};
char moves[4] = {'L', 'R', 'U', 'D'};
ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {-1, 1, 0, 0};
bool vis[105][105];
ll dist[105][105];

bool valid(ll r, ll c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

pair<ll, ll> move(char c) {
	cout << c << endl;
	ll row, col;
	cin >> row >> col;
	if (row == -1) exit(0);
	if (make_pair(row - 1, col - 1) == pos) {
		exit(0);
	}
	return make_pair(row - 1, col - 1);
}

void finish() {
	queue<pair<pair<ll, ll>, ll>> q;
	
	q.push(make_pair(pos, 0));
	
	while (!q.empty()) {
		pair<pair<ll, ll>, ll> x = q.front();
		q.pop();
		
		pair<ll, ll> p = x.f;
		
		if (vis[p.f][p.s]) continue;
		vis[p.f][p.s] = 1;
		dist[p.f][p.s] = x.s;
		
		for (ll d = 0; d < 4; d++) {
			ll nr = p.f + dr[d], nc = p.s + dc[d];
			if (valid(nr, nc) && !vis[nr][nc] && mat[nr][nc] != '*') {
				q.push(make_pair(make_pair(nr, nc), x.s + 1));
			}
		}
	}
	
	while (1) {
		for (ll d = 0; d < 4; d++) {
			ll nr = cur.f + dr[d], nc = cur.s + dc[d];
			if (valid(nr, nc) && dist[nr][nc] < dist[cur.f][cur.s] && mat[nr][nc] != '*') {
				cur = move(moves[d]);
				break;
			}
		}
	}
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) cin >> mat[i];
		
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] == 'F') {
				pos = {i, j};
			}
		}
	}
		
	if (m > 1 && mat[0][1] != '*') { // right open
		pair<ll, ll> nxt = move('L');
		if (nxt != cur) {
			cur = nxt;
			swap(moves[0], moves[1]);
		}
						
		bool at_top = 1;
		ll down_pos = -1;
		if (n > 1) {
			for (ll i = 0; i < m; i++) {
				if (mat[1][i] != '*') {
					at_top = 0;
					down_pos = i;
					break;
				}
			}
		}
						
		if (at_top) finish();
				
		while (cur.s != down_pos) {
			cur = move(moves[down_pos > cur.s]);
		}
				
		nxt = move('U');
		if (nxt != cur) {
			cur = nxt;
			swap(moves[2], moves[3]);
		}
		
		finish();
	} else {
		pair<ll, ll> nxt = move('U');
		if (nxt != cur) {
			cur = nxt;
			swap(moves[2], moves[3]);
		}
		
		bool at_left = 1;
		ll right_pos = -1;
		if (m > 1) {
			for (ll i = 0; i < n; i++) {
				if (mat[i][1] != '*') {
					at_left = 0;
					right_pos = i;
					break;
				}
			}
		}
		
		if (at_left) finish();
		
		while (cur.f != right_pos) {
			cur = move(moves[2 + (right_pos > cur.f)]);
		}
		
		nxt = move('L');
		if (nxt != cur) {
			cur = nxt;
			swap(moves[0], moves[1]);
		}
		
		finish();
	}
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