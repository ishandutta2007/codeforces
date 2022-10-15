#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v =split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int N, M;
vector<tuple<int, int, int> > edges;
vector<int> adj[MAXN];

LL f(int w) {
	int lo = 0, hi = 20000;
	while (lo != hi) {
		int mid = (lo + hi + 1) >> 1;
		if (mid * (mid + 1) / 2 < w) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	LL n = lo;
	return (n + 1) * w - n * (n + 1) * (n + 2) / 6;
}

// tarjan stuff
int disc[MAXN];
int low[MAXN];
int scc[MAXN];
int sccnum = 0;
int dtime = 0;
stack<int> st;
bool stm[MAXN];

void tarjanUtil(int n) {
	disc[n] = dtime++;
	low[n] = disc[n];
	st.push(n);
	stm[n] = true;
	for (int m : adj[n]) {
		if (disc[m] == -1) {
			tarjanUtil(m);
			low[n] = min(low[n], low[m]);
		}
		else if (stm[m]) {
			low[n] = min(low[n], low[m]);
		}
	}

	if (low[n] == disc[n]) {
		int u;
		while (!st.empty()) {
			u = st.top();
			st.pop();
			if (u == n) {
				scc[u] = sccnum;
				stm[u] = false;
				break;
			}
			scc[u] = sccnum;
			stm[u] = false;
		}
		sccnum++;
	}
}

void tarjan() {
	memset(scc, -1, sizeof scc);
	memset(disc, -1, sizeof disc);
	for (int i = 0; i < N; i++) {
		if (scc[i] == -1) {
			tarjanUtil(i);
		}
	}
}

// DAG between SCCs
vector<pair<int, int> > adj2[MAXN];
LL fun[MAXN];
LL dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		edges.emplace_back(a, b, c);
		adj[a].push_back(b);
	}

	tarjan();

	for (auto e : edges) {
		int u = scc[get<0>(e)];
		int v = scc[get<1>(e)];
		int w = get<2>(e);
		if (u == v) {
			fun[u] += f(w);
		}
		else {
			adj2[u].emplace_back(v, w);
		}
	}

	// tarjan takes care of toposort for us
	// reverse topological ordering
	for (int i = 0; i < sccnum; i++) {
		dp[i] = fun[i];
		for (auto p : adj2[i]) {
			dp[i] = max(dp[i], fun[i] + p.second + dp[p.first]);
		}
	}

	int S; cin >> S; --S;

	cout << dp[scc[S]] << endl;
	return 0;
}