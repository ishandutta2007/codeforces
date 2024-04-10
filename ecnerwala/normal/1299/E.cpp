#include<bits/stdc++.h>
using namespace std;

#define TEST false

#if TEST
vector<int> P;
#endif

bool query(const vector<int>& v) {
	cout << "?" << ' ' << v.size();
	for (int a : v) cout << ' ' << a+1;
	cout << '\n' << flush;

#if TEST
	int sum = 0; for (int a : v) sum += P[a];
	return (sum % int(v.size())) == 0;
#else
	char r; cin >> r;
	assert('0' <= r && r <= '1');
	return r - '0';
#endif
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
#if TEST
	P.resize(N);
	for (int i = 0; i < N; i++) { cin >> P[i]; P[i]--; }
	assert(P[0] <= N-1-P[0]);
#endif
	vector<vector<int>> buckets(1);
	for (int i = 0; i < N; i++) {
		buckets[0].push_back(i);
	}
	while (buckets[0].size() >= 3) {
		int b = int(buckets.size());
		vector<int> cnd(2*b);
		for (int i = 0; i < b; i++) {
			assert(buckets[i].size() >= 2);
			cnd[2*i+0] = buckets[i][0];
			cnd[2*i+1] = buckets[i].back();
		}

		bool initVal = query(cnd);

		buckets.resize(2*b);
		for (int i = 0; i < b; i++) {
			assert(buckets[i].size() >= 2);
			if (buckets[i].size() >= 3) {
				int newLen = 1;

				bool lastRes = false;
				for (int z = 1; z+1 < int(buckets[i].size()); z++) {
					cnd[2*i+0] = buckets[i][z];
					lastRes = query(cnd);
					if (lastRes == initVal) {
						buckets[i][newLen++] = buckets[i][z];
					} else {
						buckets[b+i].push_back(buckets[i][z]);
					}
				}

				assert(cnd[2*i+1] == buckets[i].back());
				cnd[2*i+1] = buckets[i][0];
				if (query(cnd) == lastRes) {
					buckets[i][newLen++] = buckets[i].back();
				} else {
					buckets[b+i].push_back(buckets[i].back());
				}

				cnd[2*i+0] = buckets[i][0];
				cnd[2*i+1] = buckets[i].back();

				buckets[i].resize(newLen);
				if (buckets[i].size() < buckets[b+i].size()) {
					swap(buckets[i], buckets[b+i]);
				}
			} else if (buckets[i].size() == 2) {
				buckets[b+i].push_back(buckets[i].back());
				buckets[i].resize(1);
			} else assert(false);
			assert(buckets[i].size() >= buckets[b+i].size());
			assert(buckets[i].size() - buckets[b+i].size() <= 1);
		}
	}

	while (buckets.size() > 1) {
		int b = int(buckets.size()) / 2;

		for (int i = 0; i < b; i++) {
			if (buckets[i].size() == buckets[b+i].size()) {
				int s = int(buckets[i].size());
				if (s >= 2) {
					if (s % 2 == 0) {
						if (!query({buckets[b+i][s/2-1], buckets[i][s/2], buckets[b+i][s/2]})) {
							reverse(buckets[i].begin(), buckets[i].end());
						}
						if (!query({buckets[i][s/2-1], buckets[b+i][s/2-1], buckets[i][s/2]})) {
							reverse(buckets[b+i].begin(), buckets[b+i].end());
						}
					} else {
						if (!query({buckets[i][s/2], buckets[b+i][s/2], buckets[i][s/2+1]})) {
							reverse(buckets[i].begin(), buckets[i].end());
						}
						if (!query({buckets[b+i][s/2-1], buckets[i][s/2], buckets[b+i][s/2]})) {
							reverse(buckets[b+i].begin(), buckets[b+i].end());
						}
					}
				}
			} else if (buckets[i].size() == buckets[b+i].size() + 1) {
				int s = int(buckets[b+i].size());
				assert(s >= 1);
				if (s >= 2) {
					if (s % 2 == 0) {
						if (!query({buckets[i][s/2], buckets[b+i][s/2], buckets[i][s/2+1]})) {
							reverse(buckets[b+i].begin(), buckets[b+i].end());
						}
					} else {
						if (!query({buckets[b+i][s/2], buckets[i][s/2+1], buckets[b+i][s/2+1]})) {
							reverse(buckets[b+i].begin(), buckets[b+i].end());
						}
					}
				}
			} else assert(false);

			vector<int> newBucket(buckets[i].size() + buckets[b+i].size());
			for (int z = 0; z < int(newBucket.size()); z++) {
				newBucket[z] = buckets[b*(z%2) + i][z/2];
			}
			buckets[i] = std::move(newBucket);
		}

		buckets.resize(b);
	}

	vector<int> ans(N);
	for (int i = 0; i < N; i++) ans[buckets[0][i]] = i;
	if (N-1-ans[0] < ans[0]) {
		for (int& v: ans) v = N-1-v;
	}
	cout << "!";
	for (int a : ans) cout << ' ' << a+1;
	cout << '\n';

#if TEST
	assert(ans == P);
#endif

	return 0;
}