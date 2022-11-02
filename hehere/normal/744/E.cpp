#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
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
ostream& operator << (ostream &cout, const pair<A, B> &p) {
	return cout << "(" << p.first << ", " << p.second << ")";
}

const int maxN = 30 + 2;
const int maxL = 100000 + 5;
int n, ls[maxN];
string s[maxN]; 
vector<pii> E[maxL];

vector<int> AlgoZ(string s) {
	int n = s.length();
	vector<int> f(n, 0);
	int L = 0, R = 0;
	for(int i = 1; i < n; ++i) {
		if(L <= i && i < R) f[i] = min(f[i - L], R - i);
		while(i + f[i] < n && s[f[i]] == s[i + f[i]]) ++f[i];
		if(i + f[i] > R) L = i, R = i + f[i];
	}
	return f;
}

vector<int> G[maxL];
int vis[maxL];
int nowl, nowr;
bool valid(int u) {
	return (nowl <= u && u < nowr) || u == ls[n];
}
bool DFS(int u) {
	vis[u] = 1;
	for(int v : G[u]) if(valid(v)) {
		if(vis[v] == 0) {
			if(!DFS(v)) return false;
		} else if(vis[v] == 1) {
			return false;
		} else {
			assert(vis[v] == 2);
		}
	}
	vis[u] = 2;
	return true;
}
bool check(int L, int R) { // acyclic?
	nowl = L; nowr = R;
	memset(vis, 0, sizeof(vis));
	for(int i = L; i < R; ++i) if(!vis[i]) {
		if(!DFS(i)) return false;
	}
	if(!vis[ls[n]] && !DFS(ls[n])) return false;
	return true;
}

void add(const vector<pii> &E) {
	for(auto p : E)
		G[p.first].push_back(p.second);
}

void erase(const vector<pii> &E) {
	for(auto p : E)
		G[p.first].erase(find(G[p.first].begin(), G[p.first].end(), p.second));
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	ls[0] = 0;
	for(int i = 1; i <= n; ++i) cin >> s[i], ls[i] = ls[i - 1] + s[i].length();
	for(int i = 1; i <= n; ++i) G[ls[n]].push_back(ls[i - 1]);
	for(int i = 1; i <= n; ++i) {
		string t = s[i];
		for(int j = 1; j <= n; ++j) t += s[j];
		auto f = AlgoZ(t);
		for(int j = 1; j <= n; ++j) {
			for(int k = 0; k < (int)s[j].size(); ++k) {
				int leng = f[ls[j - 1] + k + s[i].size()];
				chmin(leng, (int)s[i].size());
				chmin(leng, (int)s[j].size() - k);
				if(leng == (int)s[i].size() && leng == (int)s[j].size() - k)
					if(k) E[i].emplace_back(ls[j - 1] + k, ls[n]); else;
				else if(leng == (int)s[i].size() && leng < (int)s[j].size() - k)
					E[i].emplace_back(ls[j - 1] + k, ls[j - 1] + k + leng);
				else if(leng < (int)s[i].size() && leng == (int)s[j].size() - k)
					E[i].emplace_back(ls[j - 1] + k, ls[i - 1] + leng);
			}
		}
		displayv(E[i]);
	}
	int ans = 0;
	for(int l = 1, r = 0; l <= n; ++l) {
		chmax(r, l - 1);
		while(r + 1 <= n) {
			add(E[++r]);
			if(!check(ls[l - 1], ls[r])) {
				erase(E[r--]);
				break;
			}
		}
//		eprintf("[%d, %d]\n", L, R);
		ans += r - l + 1;
		if(l <= r) erase(E[l]);
	}
	cout << ans << endl;
	return 0;
}