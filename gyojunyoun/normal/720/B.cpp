#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }

const bool debug = 0;
const int MAXN = 10005;
const int MAXM = 20005;

vector<int> G[MAXN];
int prt[14][MAXN], prte[MAXN], dep[MAXN];

vector<int> CI[MAXM];

vector<vector<int>> CV;
bitset<MAXM> isCVE;
int cnt[MAXM];

int A[MAXM], B[MAXM], C[MAXM];
bitset<MAXM> isE, isCE, chk;

int ud[MAXN];

int N, M, Ans;

int uf(int i) { return i == ud[i] ? i : (ud[i] = uf(ud[i])); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }

int lca(int a, int b) {
	if(dep[a] > dep[b]) swap(a, b);
	const int dt = dep[b] - dep[a];
	for(int i = 0; i < 14; i++) if(dt & (1<<i))
		b = prt[i][b];
	if(a == b) return a;
	for(int i = 14; i--;) if(prt[i][a] != prt[i][b]) {
		a = prt[i][a]; b = prt[i][b];
	}
	return prt[0][a];
}

void dfs(int i) {
	for(int e : G[i]) {
		int v = A[e] + B[e] - i;
		if(dep[v]) continue;
		dep[v] = dep[i] + 1;
		prt[0][v] = i;
		prte[v] = e;
		dfs(v);
	}
}
void dfs1(int i, int rt, vector<int> &V) {
	if(i == rt) return;
	V.eb(C[prte[i]]);
	isCE[prte[i]] = true;
	dfs1(prt[0][i], rt, V);
}

int main() {
	ios::sync_with_stdio(false);
	iota(ud, ud+MAXN, 0);

	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		if(uf(A[i]) == uf(B[i])) continue;
		G[A[i]].eb(i); G[B[i]].eb(i);
		uf(A[i], B[i]);
		isE[i] = true;
	}

	dep[1] = 1; dfs(1);
	for(int j = 1; j < 14; j++) for(int i = 1; i <= N; i++)
		prt[j][i] = prt[j-1][prt[j-1][i]];
	
	for(int i = 1, a, b, c; i <= M; i++) if(!isE[i]) {
		a = A[i]; b = B[i];
		c = lca(a, b);

		CV.eb(vector<int>());
		dfs1(a, c, CV.back());
		dfs1(b, c, CV.back());
		CV.back().eb(C[i]);
	}

	for(int i = 1; i <= M; i++) if(!isCE[i] && isE[i])
		chk[C[i]] = true;

	if(debug) {
		for(auto &v : CV) {
			for(int e : v) printf("%d ", e);
			puts("");
		}
	}

	for(auto &V : CV) {
		for(int v : V) cnt[v]++;
		sorv(V);
	}
	for(int vi = 0; vi < sz(CV); vi++)
		for(int v : CV[vi])
			CI[v].eb(vi);

	vector<int> PQ;

	for(int vi = 0; vi < sz(CV); vi++) {
		auto &V = CV[vi];
		bool flag = false;

		for(int i = 1, n = sz(V); i < n; i++) if(V[i-1] == V[i]) {
			flag = true;
			for(int v : V) chk[v] = true;
			break;
		}
		if(flag) {
			isCVE[vi] = true;
			for(int v : V) {
				for(int i : CI[v]) {
					if(isCVE[i]) continue;
					isCVE[i] = true;
					PQ.eb(i);
				}
			}
			continue;
		}

		for(int v : V) {
			if(chk[v]) {
				for(int t : V) chk[t] = true;
				flag = true;
				break;
			}
		}
		if(flag) {
			isCVE[vi] = true;
			for(int v : V) {
				chk[v] = true;
				for(int i : CI[v]) {
					if(isCVE[i]) continue;
					isCVE[i] = true;
					PQ.eb(i);
				}
			}
			continue;
		}
	}

	for(;;) {
		for(int vi; !PQ.empty();) {
			vi = PQ.back(); PQ.pop_back();
			for(int v : CV[vi]) {
				chk[v] = true;
				for(int i : CI[v]) {
					if(isCVE[i]) continue;
					isCVE[i] = true;
					PQ.eb(i);
				}
			}
		}

		int idx = -1;
		for(int i = 0; i < sz(CV); i++)
			if(!isCVE[i]) {
				idx = i;
				break;
			}
		if(idx < 0) break;

		int col = CV[idx][0];
		for(int v : CV[idx]) if(cnt[col] < cnt[v]) col = v;
		
		isCVE[idx] = true;
		for(int v : CV[idx]) if(col != v) {
			chk[v] = true;
			for(int i : CI[v]) {
				if(isCVE[i]) continue;
				isCVE[i] = true;
				PQ.eb(i);
			}
		}
	}

	for(int i = 0; i <= M; i++) if(chk[i]) Ans++;
	cout << Ans << endl;
	return 0;
}