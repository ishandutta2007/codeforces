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


vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));
	
	if (low == val[j]) {
		do { 
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while(x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}

template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int convert(int x){
	if(x > 0){
		return 2*(x-1);
	} else {
		return 2*(-x-1)+1;
	}
}

vector<int> dp;

/*struct TwoSat {
	int N;
	vector<vi> gr;
	vi values;
	
	TwoSat(int n = 0) : N(n), gr(2*n) {}
	
	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f^1].push_back(j);
		gr[j^1].push_back(f);
	}
	void set_value(int x) { either(x, x); }
	
	void at_most_one(const vi& li) {
		if (sz(li) <= 1) return ;
		rep(i,2,sz(li)) {
			int next = add_var();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}
	
	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = ~(x & 1);
		} while (x != i);
		return val[i] = low;
		
	}
	
}*/

void solve(){
	
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<pair<int,int> > a(m);
	vector<vector<int> > edges(2*n);
	
	dp.clear(); dp.resize(2*n, -1);
	
	for(int i = 0; i < m; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first = convert(a[i].first);
		a[i].second = convert(a[i].second);
		edges[1 ^ a[i].first].push_back(a[i].second);
		edges[1 ^ a[i].second].push_back(a[i].first);
	}
	
	scc(edges, [&] (vi& comp) {
		int val = -1;
		for (int v : comp) {
			if (s[v/2] == 'A') val = max(val, v);
			for (int nxt : edges[v]) {
				val = max(val, dp[nxt]);
			}
		}
		for (int v : comp) {
			dp[v] = val;
		}
	});
	
	for (int i = 0; i < 2*n; i++) {
		if (i < dp[i]) {
			// not i must be true
			edges[i].push_back(i^1);
		}
	}
	
	int bad = 0;
	for(int b = 0; b < 2; b++){
		vector<vector<int> > e2 = edges;
		for(int i = 0; i < n; i++){
			if(s[i] == 'A'){
				e2[2*i ^ b].push_back(2*i ^ (!b));
			}
		}
		scc(e2, [&] (vi& comp) {
			vi f = comp;
			sort(f.begin(), f.end());
			for(int i = 0; i + 1 < f.size(); i++){
				if((f[i] ^ 1) == f[i+1]){
					bad = 1;
				}
			}
		});
	}
	if(bad){
		cout << "FALSE" << '\n';
	} else {
		cout << "TRUE" << '\n';
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}