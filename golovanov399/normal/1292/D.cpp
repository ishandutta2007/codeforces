#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 5055;
int erat[N];
vector<int> primes;

const int P = 700;
int fd[N][P];
int sfd[N][P];

int max_pr[N];
int pr_id[N];
int max_diff[N][N];

int critical[N][N];
int dist[N][N];

int cnts[N];

const int M = N * 13;
int crits[M];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			for (int j = i * i; j < N; j += i) {
				if (erat[j] == 0) {
					erat[j] = i;
				}
			}
		}
		if (erat[i] == i) {
			primes.push_back(i);
		}
	}
	for (int i = 0; i < (int)primes.size(); ++i) {
		pr_id[primes[i]] = i;
	}

	max_pr[1] = -1;
	for (int i = 2; i < N; ++i) {
		int p = erat[i];
		max_pr[i] = max(max_pr[i / p], pr_id[p]);
	}
	
	for (int i = 1; i < N; ++i) {
		memcpy(fd[i], fd[i - 1], sizeof(int) * P);
		int x = i;
		while (x > 1) {
			int p = erat[x];
			x /= p;
			fd[i][pr_id[p]] += 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		sfd[i][0] = 0;
		for (int j = 0; j < P - 1; ++j) {
			sfd[i][j + 1] = sfd[i][j] + fd[i][j];
		}
	}
	
	for (int i = 0; i < N; ++i) {
		int cur = -1;
		max_diff[i][i] = cur;
		for (int j = i + 1; j < N; ++j) {
			cur = max(cur, max_pr[j]);
			max_diff[i][j] = max_diff[j][i] = cur;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int md = max_diff[i][j];
			critical[i][j] = md == -1 ? 0 : sfd[i][md] + fd[i][md] - min(fd[i][md], fd[j][md]);
			dist[i][j] = md == -1 ? 0 : sfd[i][md] + sfd[j][md] + abs(fd[i][md] - fd[j][md]);
			assert(critical[i][j] < M);
		}
	}

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		cnts[nxt()] += 1;
	}

	long long ans = 1e18;
	for (int i = 0; i < N; ++i) {
		long long cur = 0;
		for (int j = 0; j < N; ++j) {
			cur += 1ll * cnts[j] * dist[i][j];
			crits[critical[i][j]] += cnts[j];
		}
		int cur_income = -n;
		for (int j = 0; j < M && cur_income <= 0; ++j) {
			ans = min(ans, cur);
			cur_income += 2 * crits[j];
			cur += cur_income;
		}
		ans = min(ans, cur);
		for (int j = 0; j < N; ++j) {
			crits[critical[i][j]] -= cnts[j];
		}
	}

	cout << ans << "\n";

	return 0;
}