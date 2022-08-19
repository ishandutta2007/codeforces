#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 200;
const int MAXM = 200;

int N, M;
int A[MAXN];
pii E[MAXM];

set<int> primes;

void factor(int a) {
	for(int j = 2; j * j <= a; j++) {
		if(a % j == 0) primes.insert(j);
		while(a % j == 0) a /= j;
	}
	if(a > 1) primes.insert(a);
}

const int MAXV = MAXN * 30;

int vp[MAXN];

int L, R;
bool vis[MAXV];
vector<int> adj[MAXV];
int prv[MAXV];

int pref[MAXN];

bool dfs(int a) {
	if(vis[a]) return false;
	vis[a] = true;
	for(int b : adj[a]) {
		if(prv[b] == -1) {
			prv[b] = a;
			return true;
		} else {
			int c = prv[b];
			prv[b] = a;
			if(dfs(c)) return true;
			prv[b] = c;
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		factor(A[i]);
	}
	for(int i = 0; i < M; i++) {
		cin >> E[i].A >> E[i].B;
		E[i].A --, E[i].B --;
		if(E[i].A % 2 != 0) swap(E[i].A, E[i].B);
	}
	int res = 0;
	for(int p : primes) {
		pref[0] = pref[1] = 0;
		for(int i = 0; i < N; i++) {
			vp[i] = 0;
			for(int v = A[i]; v % p == 0; v /= p) vp[i] ++;
			pref[i + 2] = pref[i] + vp[i];
		}

		for(int l = 0; l < pref[(N + 1) / 2 * 2]; l++) adj[l].clear();
		for(int i = 0; i < M; i++) {
			int a = E[i].A, b = E[i].B;
			assert(a % 2 == 0);
			assert(b % 2 == 1);


			for(int l = pref[a]; l < pref[a + 2]; l++) {
				for(int r = pref[b]; r < pref[b + 2]; r++) {
					adj[l].push_back(r);
				}
			}
		}

		memset(vis, false, sizeof(vis));
		memset(prv, -1, sizeof(prv));

		for(int i = 0; i < pref[(N + 1) / 2 * 2]; i++) {
			if(dfs(i)) {
				res++;
				memset(vis, false, sizeof(vis));
			}
		}
	}
	cout << res << '\n';
	return 0;
}