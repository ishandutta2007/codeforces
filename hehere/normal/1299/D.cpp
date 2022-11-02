#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << (x) << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

#define bs basic_string
using base = bs< int >;

base cancel(base b) {
	for(int i = 4; i >= 0; --i) if(b[i])
		for(int j = i - 1; j >= 0; --j) if(b[j] && (b[i] >> j & 1))
			b[i] ^= b[j];
	return b;
}
base addto(base b, int x) {
	for(int i = 4; i >= 0; --i) if(x >> i & 1) {
		if(b[i] == 0) {
			b[i] = x;
			return cancel(b);
		} else {
			x ^= b[i];
		}
	}
	assert(x == 0);
	return b;
}
bool contains(base b, int x) {
	for(int i = 4; i >= 0; --i) if(x >> i & 1) {
		if(b[i]) {
			x ^= b[i];
		}
	}
	return x == 0;
}

#define merge mmmmmmm

int cnt;
vector<unsigned> cont;
map<base, int> id;
vector< vector<int> > add, merge;

void getbasis() {
	base empty = {0, 0, 0, 0, 0};
	set<base> S;
	S.insert(empty);
	queue<base> Q;
	Q.push(empty);
	while(Q.size()) {
		base b = Q.front(); Q.pop();
		for(int w = 1; w < 32; ++w) {
			if(!S.count(addto(b, w)))
				S.insert(addto(b, w)), Q.push(addto(b, w));
		}
	}
	cnt = 0;
	for(auto b : S) {
		id[b] = cnt++;
		cont.push_back(0);
		for(int w = 0; w < 32; ++w) if(contains(b, w))
			cont.back() |= 1u << w;
	}
	for(auto b : S) {
		add.push_back(vector<int>());
		for(int w = 0; w < 32; ++w)
			add.back().push_back(id[addto(b, w)]);
	}
	for(auto b : S) {
		merge.push_back(vector<int>());
		for(auto c : S) {
			bool valid = true;
			for(int w = 1; w < 32; ++w)
				valid &= !(contains(b, w) && contains(c, w));
			if(!valid) merge.back().push_back(-1);
			else {
				int t = id[b];
				for(int w = 1; w < 32; ++w)
					if(contains(c, w)) t = add[t][w];
				merge.back().push_back(t);
			}
		}
	}
}

const int maxN = 100000 + 5;
const LL P = 1000000007;
int n, m;
vector<pii> G[maxN];
bool major[maxN];
LL maw[maxN], dep[maxN];

vector<LL> f, g;

bool vis[maxN];
int nowb;
bool valid;

void dfs(int u, int fa) {
	vis[u] = true;
	for(auto p : G[u]) {
		int v = p.first, w = p.second;
		if(v == fa || major[v]) continue;
		if(vis[v] && u < v) { // is this good?
			int val = dep[u] ^ dep[v] ^ w;
			if(cont[nowb] >> val & 1) valid = false;
			else nowb = add[nowb][val];
		}
		if(!vis[v]) {
			dep[v] = dep[u] ^ w;
			dfs(v, u);
		}
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	getbasis();
	display(cnt);
	/*int u = 0;
	display(cont[u] >> 0 & 1);
	display(cont[u] >> 1 & 1);
	u = add[u][2];
	display(cont[u] >> 1 & 1);
	display(cont[u] >> 2 & 1);
	u = add[u][1];
	display(cont[u] >> 1 & 1);
	display(cont[u] >> 2 & 1);
	display(cont[u] >> 3 & 1);*/
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		G[x].emplace_back(y, w);
		G[y].emplace_back(x, w);
	}
	major[1] = true; maw[1] = 0;
	for(auto p : G[1]) major[p.first] = true, maw[p.first] = p.second;
	
	f.assign(cnt, 0);
	f[0] = 1;
	memset(vis, 0, sizeof(vis));
	for(auto p : G[1]) {
		int u = p.first, fr = -1, lv = -1;
		for(auto q : G[u]) if(major[q.first] && q.first != 1) fr = q.first, lv = q.second ^ maw[q.first] ^ maw[u];
		if(fr != -1 && u > fr) continue;
		nowb = 0; valid = true;
		dfs(u, -1);
		if(fr != -1) dfs(fr, -1);
		g = f;
		f.assign(cnt, 0);
		display(u); display(fr); display(lv);
		display(nowb);
		display(valid);
		if(fr == -1) {
			for(int u = 0; u < cnt; ++u) {
				(f[u] += g[u]) %= P;
				bool va = valid && (merge[u][nowb] != -1);
				if(va) (f[merge[u][nowb]] += g[u]) %= P;
			}
		} else {
			int _nowb = add[nowb][lv];
			bool _valid = valid && ((cont[nowb] >> lv & 1) == 0);
			for(int u = 0; u < cnt; ++u) {
				(f[u] += g[u]) %= P;
				bool va = valid && (merge[u][nowb] != -1);
				if(va) (f[merge[u][nowb]] += g[u] * 2) %= P;
				va = _valid && (merge[u][_nowb] != -1);
				if(va) (f[merge[u][_nowb]] += g[u]) %= P;
			}
		}
	}
	LL ans = accumulate(f.begin(), f.end(), 0LL) % P;
	cout << ans << endl;
	return 0;
}