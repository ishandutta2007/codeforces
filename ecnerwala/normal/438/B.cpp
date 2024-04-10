#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MAXN = 2e5;
const int MAXM = 2e5;

int N, M;
int A[MAXN];
int V[MAXN];

pip E[MAXM];

int par[MAXN];
int rank[MAXN];
ll sz[MAXN];

int getPar(int a) {
	if(par[a] == a) return a;
	return par[a] = getPar(par[a]);
}

ll merge(int a, int b) {
	//number of connections formed
	a = getPar(a), b = getPar(b);
	if(a == b) return 0;

	ll res = sz[a] * sz[b];

	if(rank[a] < rank[b]) swap(a, b);

	par[b] = a;
	if(rank[a] == rank[b]) rank[a] ++;
	sz[a] += sz[b];

	return res;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < M; i++) {
		int x, y; cin >> x >> y; x--, y--;
		E[i] = pip(min(A[x], A[y]), pii(x, y));
	}
	sort(E, E + M);
	reverse(E, E + M);
	ll res = 0;
	for(int i = 0; i < M; i++) {
		res += merge(E[i].second.first, E[i].second.second) * E[i].first;
	}
	cout << fixed <<  setprecision(6) << 2 * double(res) / N / (N - 1) << '\n';
	return 0;
}