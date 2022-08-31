#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const int MAXM = 2e5;

ll N, M;
ll K;

int F[MAXN];

int V = 0;
int vis[MAXN];

vector<int> adj[MAXN];

ll good[MAXN];
ll tot[MAXN];

struct frac {
	ll num, den;
	frac(ll a, ll b) : num(a), den(b) {}
};
inline bool operator < (frac a, frac b) { return a.num * b.den < b.num * a.den; }

inline bool operator > (frac a, frac b) { return b < a; }

typedef pair<frac, int> pfi;
#define A first
#define B second

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K;

	for(int i = 0; i < K; i++) {
		cin >> F[i];
		F[i] --;
	}

	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 0; i < N; i++) {
		tot[i] = good[i] = ll(adj[i].size());
	}

	for(int i = 0; i < K; i++) {
		int f = F[i];
		for(int a : adj[f]) {
			good[a] --;
		}
		vis[f] = -1;
	}

	priority_queue<pfi, vector<pfi>, greater<pfi>> pq;

	for(int i = 0; i < N; i++) {
		if(vis[i]) continue;
		pq.push(pfi(frac(good[i], tot[i]), i));
	}

	frac best(0, 1);
	int res = 0;
	while(!pq.empty()) {
		int a = pq.top().B;
		frac f = pq.top().A;
		pq.pop();
		if(vis[a]) continue;

		vis[a] = ++V;

		if(!(f < best) /* f >= best */) {
			best = f;
			res = vis[a];
		}

		for(int b : adj[a]) {
			good[b] --;
			if(!vis[b]) pq.push(pfi(frac(good[b], tot[b]), b));
		}
	}

	assert(V == N - K);
	cout << V - res + 1 << '\n';
	for(int i = 0; i < N; i++) {
		if(vis[i] >= res) cout << i + 1 << ' ';
	}
	cout << '\n';
	return 0;
}