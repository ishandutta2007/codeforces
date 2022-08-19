#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N, K;
int A[MAXN * 4];

int pref[MAXN * 4];

pair<ll, ll> dist[MAXN][20];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	int tot = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		tot += A[i];
	}
	assert(tot % N == 0);
	int avg = tot / N;
	for (int i = 0; i < N; i++) {
		A[i] -= avg;
	}

	for (int i = 0; i < N; i++) {
		A[i+3*N] = A[i+2*N] = A[i+N] = A[i];
	}

	pref[0] = 0;
	for (int i = 0; i < 4 * N; i++) {
		pref[i+1] = pref[i] + A[i];
	}

	{
		vector<map<int, int>> prefMatches(N);

		for (int i = 2 * N; i >= 0; i--) {
			if (i < N) {
				if (prefMatches[(i+1)%(K-1)].count(pref[i]) && prefMatches[(i+1) % (K-1)][pref[i]] <= i+N) {
					int l = prefMatches[(i+1) % (K-1)][pref[i]] - i;
					dist[i][0] = {l, (l-1) / (K-1)};
				} else {
					dist[i][0] = {N, (N-1 + (K-2)) / (K-1)};
				}
			}
			prefMatches[i % (K-1)][pref[i]] = i;
		}
	}


	for (int z = 0; z < 19; z++) {
		for (int i = 0; i < N; i++) {
			int j = int((i + dist[i][z].first) % N);
			dist[i][z+1] = {
				dist[i][z].first + dist[j][z].first,
				dist[i][z].second + dist[j][z].second,
			};
		}
	}
	int bestStart = -1;
	int ans = N+1;
	for (int i = 0; i < N; i++) {
		int cur = i;
		int cost = 0;
		for (int z = 19; z >= 0; z--) {
			if (cur + dist[cur % N][z].first < i + N) {
				cost += int(dist[cur % N][z].second);
				cur += int(dist[cur % N][z].first);
			}
		}
		assert(cur < i + N);
		cost += (i + N - cur - 1 + (K-2)) / (K-1);
		if (cost < ans) {
			ans = cost;
			bestStart = i;
		}
	}

	cerr << bestStart << '\n';
	cout << ans << '\n';

	for (int st = bestStart; st < bestStart + N; ) {
		int en = st + int(dist[st%N][0].first);
		en = min(en, bestStart + N);

		assert(pref[en] == pref[st]);
		while ((en - st - 1) % (K-1) != 0) {
			assert(en >= bestStart + N);
			pref[en+1] = pref[en];
			en++;
		}
		assert(pref[en] == pref[st]);
		cerr << st << ' ' << en << '\n';

		unordered_set<int> moved;
		auto canMove = [&](int a) {
			if (moved.count(a)) return false;
			int b = a + K;
			assert(st <= a && b <= en);
			assert((a - st) % (K-1) == 0);
			return (pref[a] - pref[st] <= 0 || pref[a+1] - pref[st] <= 0) && (pref[b] - pref[st] >= 0 || pref[b-1] - pref[st] >= 0);
		};
		unordered_set<int> moves;
		for (int a = st; a+K <= en; a += K-1) {
			if (canMove(a)) {
				moves.insert(a);
			}
		}
		while (!moves.empty()) {
			auto it = moves.begin();
			int a = *it;
			moves.erase(it);
			moved.insert(a);
			int b = a+K;
			for (int i = 1; i <= K-1; i++) {
				pref[a+i] = pref[st];
			}

			cout << (a%N);
			for (int i = 0; i < K; i++) {
				if (a+i < bestStart + N) {
					A[(a+i)%N] = pref[a+i+1] - pref[a+i];
				}
				cout << " " << A[(a+i)%N]+avg;
			}
			cout << '\n';

			if (a > st) {
				if (canMove(a - (K-1))) {
					moves.insert(a - (K-1));
				} else {
					moves.erase(a - (K-1));
				}
			}
			if (b < en) {
				if (canMove(a + (K-1))) {
					moves.insert(a + (K-1));
				} else {
					moves.erase(a + (K-1));
				}
			}
		}

		st = en;
	}

	return 0;
}