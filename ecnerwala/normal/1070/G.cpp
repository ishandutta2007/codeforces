#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200;
const int MAXM = MAXN;
int N;
int M;

ll val[MAXN];

int S[MAXM];
ll H[MAXM];
bool used[MAXM];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> S[i] >> H[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
	}

	for (int mid = 1; mid <= N; mid++) {
		memset(used, false, sizeof(used));
		int lpos = mid + 1;
		int rpos = mid - 1;
		vector<int> res;
		while (int(res.size()) < M) {
			bool found = false;
			for (int i = 1; i <= M; i++) {
				if (used[i]) continue;
				assert(val[S[i]] == 0);
				bool good = true;
				int cur = H[i];
				assert(cur >= 0);
				if (S[i] <= mid) {
					for (int p = S[i]; p < lpos; p++) {
						cur += val[p];
						if (cur < 0) {
							good = false;
							break;
						}
					}
					// we care about lpos..S
				} else {
					for (int p = S[i]; p > rpos; p--) {
						cur += val[p];
						if (cur < 0) {
							good = false;
							break;
						}
					}
				}
				if (good) {
					assert(cur >= 0);
					found = true;
					res.push_back(i);
					used[i] = true;
					lpos = min(lpos, min(S[i], mid));
					rpos = max(rpos, max(S[i], mid));
				}
			}
			if (!found) {
				break;
			}
		}
		if (int(res.size()) < M) {
			continue;
		}
		cout << mid << '\n';
		for (int i = 0; i < M; i++) {
			cout << res[i] << " \n"[i==(M-1)];
		}
		return 0;
	}
	cout << -1 << '\n';
	return 0;
}