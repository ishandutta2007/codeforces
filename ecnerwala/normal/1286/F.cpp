#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	// for a tree of N items, you use N-1 edges, so parity must be N-1 total
	// If you just subtract 1, then the parity must be 1
	int N; cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			A.erase(A.begin() + i);
			N--, i--;
		}
	}

	for (int i = 0; i < N; i++) {
		assert(A[i]);
	}

	vector<ll> Asum(1<<N);
	for (int i = 0; i < N; i++) {
		for (int m = 0; m < (1<<i); m++) {
			Asum[m|(1<<i)] = Asum[m] + A[i];
		}
	}

	vector<bool> isTree(1<<N);
	{
		int L = int(N * 0.77);
		assert(0 <= L && L <= N);

		{
			vector<ll> sums;
			sums.reserve(1<<L);
			for (int ml = 0; ml < (1 << L); ml++) {
				sums.clear();
				for (int v = ml&(ml-1); v; --v &= ml) {
					assert(0 < v && v < ml);
					sums.push_back(Asum[ml] - 2 * Asum[v]);
				}
				sort(sums.begin(), sums.end());
				for (int mr = 0; mr < (1<<N); mr += (1<<L)) {
					int n = __builtin_popcount(ml | mr);
					if (n <= 1) continue;
					if ((Asum[ml] ^ Asum[mr] ^ n ^ 1) & 1) {
						continue;
					}

					bool isGood = false;
					for (int v = mr; true; --v &= mr) {
						ll val = Asum[mr] - 2 * Asum[v];
						if ((ml || v < mr) && v) {
							if (abs(val + Asum[ml]) <= n-1) {
								isGood = true;
								break;
							}
						}
						if ((ml || v) && v < mr) {
							if (abs(val - Asum[ml]) <= n-1) {
								isGood = true;
								break;
							}
						}

						auto it = lower_bound(sums.begin(), sums.end(), -val);
						if (it != sums.end()) {
							if (*it + val <= n-1) {
								isGood = true;
								break;
							}
						}
						if (it != sums.begin()) {
							--it;
							if (*it + val >= -(n-1)) {
								isGood = true;
								break;
							}
						}
						if (!v) break;
					}
					if (isGood) {
						isTree[ml | mr] = 1;
					}
				}
			}
		}
	}

	auto fft = [&](vector<uint32_t>& v) {
		for (int i = 0; i < N; i++) {
			for (int mb = 0; mb < (1 << N); mb += (2<<i)) {
				for (int m = 0; m < (1 << i); m++) {
					for (int c = 0; c <= N; c++) {
						v[(mb+(1<<i)+m)*(N+1)+c] += v[(mb+m)*(N+1)+c];
					}
				}
			}
		}
	};
	auto ifft = [&](vector<uint32_t>& v) -> bool {
		for (int i = 0; i < N; i++) {
			for (int mb = 0; mb < (1 << N); mb += (2<<i)) {
				for (int m = 0; m < (1 << i); m++) {
					for (int c = 0; c <= N; c++) {
						v[(mb+(1<<i)+m)*(N+1)+c] -= v[(mb+m)*(N+1)+c];
					}
				}
			}
		}

		bool has = false;
		for (int m = 0; m < (1<<N); m++) {
			has += (v[m*(N+1) + __builtin_popcount(m)] = bool(v[m*(N+1) + __builtin_popcount(m)]));
			for (int c = __builtin_popcount(m)+1; c <= N; c++) {
				v[m*(N+1)+c] = 0;
			}
		}
		return has;
	};
	auto mul = [&](const vector<uint32_t>& a, const vector<uint32_t>& b, vector<uint32_t>& v) {
		for (int m = 0; m < (1<<N); m++) {
			for (int c = N; c >= 0; c--) {
				uint32_t val = 0;
				for (int c1 = 0; c1 <= c; c1++) {
					val += a[m*(N+1)+c1] * b[m*(N+1)+c-c1];
				}
				v[m*(N+1)+c] = val;
			}
		}
	};

	vector<vector<uint32_t>> p2fft;
	p2fft.emplace_back((1<<N) * (N+1));
	bool hasTree = false;
	for (int m = 0; m < (1 << N); m++) {
		if (isTree[m]) {
			hasTree = true;
			p2fft[0][m*(N+1) + __builtin_popcount(m)] = 1;
		}
	}

	if (!hasTree) {
		cout << N << '\n';
		exit(0);
	}

	int l = 0;
	while (true) {
		fft(p2fft[l]);
		l++;

		if (2 * (1 << l) > N) {
			// no point in adding the next one, we'll just kill it
			break;
		}

		p2fft.emplace_back((1<<N) * (N+1));
		mul(p2fft[l-1], p2fft[l-1], p2fft[l]);

		if (!ifft(p2fft[l])) {
			p2fft.pop_back();
			break;
		}
	}

	assert(l == int(p2fft.size()));

	int ans = N;
	l--;
	ans -= (1 << l);
	vector<uint32_t> curVec = p2fft[l];
	vector<uint32_t> nVec((1<<N)*(N+1));
	while (l > 0) {
		l--;

		mul(curVec, p2fft[l], nVec);

		if (ifft(nVec)) {
			ans -= (1 << l);
			swap(curVec, nVec);
			fft(curVec);
		}
	}

	cout << ans << '\n';

	return 0;
}