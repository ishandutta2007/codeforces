#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define pcnt __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int ll

const int N =  4 * 1e5 + 5;
vector<int> Adjlist[N];
ull eulertour[2 * N], st[N], en[N], n, m, a[N], cnt = 1;
int IT[8 * N], lz[8 * N], c[2 * N];

void Eulertour(ll u, ll v){
	eulertour[cnt] = u;
	st[u] = cnt;
	cnt++;
	for(int i = 0; i < Adjlist[u].size(); i++){
		if(Adjlist[u][i] != v){
			Eulertour(Adjlist[u][i], u);
		}
	}
	eulertour[cnt] = u;
	en[u] = cnt;
	cnt++;
}

void build_tree(ll k, ll l, ll r){
	if(l == r){
		IT[k] = 1LL << c[eulertour[l]];
		return;
	}
	int mid = (l + r) / 2;
	build_tree(k * 2, l, mid);
	build_tree(k * 2 + 1, mid + 1, r);
	IT[k] = IT[2 * k] | IT[2 * k + 1];
}

void lazy_update(ll k, ll l, ll r){
	if(lz[k]) IT[k] = 1LL << lz[k];
	if(l != r && lz[k]){
		lz[2 * k] = lz[2 * k + 1] = lz[k];
	}
	lz[k] = 0;
}

void update(ll k, ll l, ll r, ll L, ll R, int color){
    lazy_update(k, l, r);
	if(r < L || l > R || L > R) return;
	if(L <= l && r <= R){
		IT[k] = 1LL << color;
		if(l != r){
			lz[2 * k] = lz[2 * k + 1] = color;
		}
		return;
	}
	if(l != r){
	    int mid = (l + r) / 2;
	    update(k * 2, l, mid, L, R, color);
	    update(k * 2 + 1, mid + 1, r, L, R, color);
	    IT[k] = IT[2 * k] | IT[2 * k + 1];
	}
}

int get(ll k, ll l, ll r, ll L, ll R){
	lazy_update(k, l, r);
	if(r < L || l > R || L > R) return 0;
	if(L <= l && r <= R) return IT[k];
	int mid = (l + r) / 2;
	return get(k * 2, l, mid, L, R) | get(k * 2 + 1, mid + 1, r, L, R);
}

int32_t main() {
    fastio;
    	ll u, v, x, num;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
	    cin >> c[i];
	    c[n + i] = c[i];
	}
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		Adjlist[u].push_back(v);
		Adjlist[v].push_back(u);
	}
	Eulertour(1, 1);
	build_tree(1, 1, 2 * n);
	for(int i = 0; i < m; i++){
		cin >> num;
		if(num == 1){
			cin >> u >> x;
			update(1, 1, 2 * n, st[u], en[u], x);
		}
		else{
			cin >> x;
			int ans = get(1, 1, 2 * n, st[x], en[x]);
			cout << __builtin_popcountll(ans) << '\n';
		}
	}
	return 0;
}