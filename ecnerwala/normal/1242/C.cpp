#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXK = 16;
const int MAXN = 5010 * MAXK;
int K;
int N;
ll A[MAXN];
int boxNum[MAXN];
ll S[MAXK];
ll T;
map<ll, int> itemNum;

int nxt[MAXN];
int vis[MAXN];
vector<int> cycItems[1<<MAXK];
int prv[1 << MAXK];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> K;
	for (int k = 0; k < K; k++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[N];
			boxNum[N] = k;
			S[k] += A[N];
			T += A[N];
			itemNum[A[N]] = N;
			N++;
		}
	}
	if (T % K != 0) {
		cout << "No" << '\n';
		exit(0);
	}
	T /= K;

	for (int i = 0; i < N; i++) {
		ll nxtA = T - (S[boxNum[i]] - A[i]);
		if (!itemNum.count(nxtA)) {
			nxt[i] = -1;
		} else {
			nxt[i] = itemNum[nxtA];
		}
	}
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		int cur = i;
		vis[cur] = i+1;
		while (true) {
			cur = nxt[cur];
			if (cur == -1) break;
			if (vis[cur] == i+1) break;
			else if (vis[cur]) {
				cur = -1;
				break;
			}
			vis[cur] = i+1;
		}
		if (cur == -1) {
			continue;
		}

		int st = cur;
		int msk = 0;
		vector<int> cyc;
		do {
			if (msk & (1 << boxNum[cur])) {
				msk = -1;
				break;
			} else {
				msk |= (1 << boxNum[cur]);
			}
			cyc.push_back(cur);
			cur = nxt[cur];
		} while (cur != st);
		if (msk == -1) {
			continue;
		}

		cycItems[msk] = cyc;
	}

	for (int m = 1; m < (1 << K); m++) {
		prv[m] = -1;
		for (int v = m; v > 0; v = (v-1) & m) {
			if (!cycItems[v].empty() && prv[m^v] != -1) {
				prv[m] = v;
				break;
			}
		}
	}

	if (prv[(1<<K) - 1] == -1) {
		cout << "No" << '\n';
		exit(0);
	}
	cout << "Yes" << '\n';
	vector<pair<ll, int>> ans(K);
	for (int m = (1 << K) - 1; m > 0; m ^= prv[m]) {
		vector<int> cyc = cycItems[prv[m]];
		for (int i = 0; i < int(cyc.size()); i++) {
			int cur = cyc[i], nxt = cyc[(i+1)%int(cyc.size())];
			ans[boxNum[nxt]] = {A[nxt], boxNum[cur]};
		}
	}
	for (int k = 0; k < K; k++) {
		cout << ans[k].first << ' ' << ans[k].second+1 << '\n';
	}

	return 0;
}