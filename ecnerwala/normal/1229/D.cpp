#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;

vector<int> perms[120];
int prod[120][120];

using bs = bitset<120>;
int G;
bs groupMask[156];
int groupSz[156];
int trans[156][120];

int cnt[156];
int ncnt[156];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	{ // generate perms
		vector<int> a(5);
		iota(a.begin(), a.end(), 0);
		int ind = 0;
		do {
			perms[ind++] = a;
		} while (next_permutation(a.begin(), a.end()));
		assert(ind == 120);
		for (int i = 0; i+1 < 120; i++) {
			assert(perms[i] < perms[i+1]);
		}
	}
	{ // generate prod
		for (int i = 0; i < 120; i++) {
			for (int j = 0; j < 120; j++) {
				vector<int> k(5);
				for (int z = 0; z < 5; z++) {
					k[z] = perms[i][perms[j][z]];
				}
				prod[i][j] = int(lower_bound(perms, perms+120, k) - perms);
				assert(perms[prod[i][j]] == k);
			}
		}
	}

	{ // generate groups
		bs trivial;
		trivial[0] = true;
		groupMask[G++] = trivial;
		for (int i = 0; i < G; i++) {
			groupSz[i] = int(groupMask[i].count());
			for (int p = 0; p < 120; p++) {
				bs newMask = groupMask[i];
				newMask[p] = true;
				vector<int> q;
				for (int v = 0; v < 120; v++) {
					if (newMask[v]) q.push_back(v);
				}
				for (int x = 0; x < int(q.size()); x++) {
					for (int y = 0; y <= x; y++) {
						int v = prod[q[x]][q[y]];
						if (!newMask[v]) {
							newMask[v] = true;
							q.push_back(v);
						}
						v = prod[q[y]][q[x]];
						if (!newMask[v]) {
							newMask[v] = true;
							q.push_back(v);
						}
					}
				}
				int j = 0;
				while (j < G && groupMask[j] != newMask) j++;
				if (j == G) {
					groupMask[j] = newMask;
					G++;
				}
				trans[i][p] = j;
			}
		}
		assert(G == 156);
	}

	int N, K; cin >> N >> K;
	memset(cnt, 0, sizeof(cnt));
	long long ans = 0;
	for (int z = 0; z < N; z++) {
		vector<int> perm(5);
		for (int i = 0; i < K; i++) {
			cin >> perm[i]; perm[i] --;
		}
		for (int i = K; i < 5; i++) {
			perm[i] = i;
		}
		int p = int(lower_bound(perms, perms + 120, perm) - perms);

		cnt[0] ++; // trivial group
		memset(ncnt, 0, sizeof(ncnt));
		for (int v = 0; v < 156; v++) {
			ncnt[trans[v][p]] += cnt[v];
		}
		for (int v = 0; v < 156; v++) {
			cnt[v] = ncnt[v];
			ans += 1ll * cnt[v] * groupSz[v];
		}
	}
	cout << ans << '\n';

	return 0;
}