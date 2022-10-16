#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAXM 100013
#define MAXC 100013
#define MAXSQRT 320

int N, M;
int C[MAXN];
vector<int> adj[MAXN];
int preorder[MAXN]; // where a node appears in preorder
int ID[MAXN]; // real value of a preorder index
int endofsubtree[MAXN]; // last element in preorder of subtree of this node
int t = 0;
int BL[MAXN];

struct query {
	int id, b, e, k;
	bool operator<(query other) {
		return BL[b] == BL[other.b] ? e < other.e : BL[b] < BL[other.b];
	}
} Q[MAXM];
int VAL[MAXN]; // mo stuff
int ANS[MAXM];

struct fenwick {
	int ar[MAXC] = {0};
	int query(int idx) {
		int ans = 0;
		for (int i = idx + 1; i > 0; i -= i & -i) {
			ans += ar[i];
		}
		return ans;
	}
	void update(int idx, int x) {
		for (int i = idx + 1; i < MAXC; i += i & -i) {
			ar[i] += x;
		}
	}
} F;

void dfs(int n, int prev=-1) {
	preorder[n] = t++;
	ID[preorder[n]] = n;

	for (int x : adj[n]) {
		if (x != prev) {
			dfs(x, n);
		}
	}

	endofsubtree[n] = t - 1;
}

inline void check(int x, int p) {
	F.update(VAL[C[x]], -1);
	VAL[C[x]] += p;
	F.update(VAL[C[x]], 1);
}

void compute() {
	int curB = Q[0].b, curE = Q[0].b - 1;
	for (int i = 0; i < M; i++) {
		query q = Q[i];
		// error(q.id, q.b, q.e);

		while (curB > q.b) check(ID[--curB], 1);
		while (curE < q.e) check(ID[++curE], 1);
		while (curB < q.b) check(ID[curB++], -1);
		while (curE > q.e) check(ID[curE--], -1);

		ANS[q.id] = F.query(MAXC - 1) - F.query(q.k - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	// okee read in the edges
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0);

	int size = sqrt(N);
	for (int i = 0; i < N; i++) {
		BL[i] = i / size;
	}

	for (int i = 0; i < M; i++) {
		int v, k;
		cin >> v >> k; v--;
		Q[i].id = i;
		Q[i].b = preorder[v];
		Q[i].e = endofsubtree[v];
		Q[i].k = k;
	}

	sort(Q, Q + M);
	compute();
	for (int i = 0; i < M; i++) {
		cout << ANS[i] << '\n';
	}

	cout.flush();
	return 0;
}