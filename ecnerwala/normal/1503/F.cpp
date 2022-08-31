#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> cards(2*N);
	vector<int> other(4*N);
	vector<int> card_id(4*N);
	for (int i = 0; i < 2*N; i++) {
		array<int, 2> card;
		for (int z = 0; z < 2; z++) {
			int a; cin >> a;
			cards[i][z] = a;
			card[z] = (z*N + (abs(a)-1)) * 2 + (a < 0);
		}
		card_id[card[0]] = card_id[card[1]] = i;
		other[card[0]] = card[1];
		other[card[1]] = card[0];
	}

	vector<bool> vis(2*N);
	vector<int> nxt(2*N, -1);
	int cur_path = -1;

	vector<pair<array<int, 2>, bool>> stk(2*N);

	for (int st = 0; st < 2*N; st++) {
		if (vis[st]) continue;

		int lo = 0, hi = 0;
		for (int e = 2*st+0; !vis[e>>1]; e = other[e^1]) {
			vis[e>>1] = true;
			array<int, 2> cur{card_id[e], card_id[e]};
			if (hi >= 2 && stk[hi-2].second == stk[hi-1].second) {
				array<int, 2> a = stk[hi-2].first, b = stk[hi-1].first, c = cur;
				if (stk[hi-1].second) swap(a, c);
				hi -= 2;
				nxt[a[1]] = b[0];
				nxt[b[1]] = c[0];
				cur = {a[0], c[1]};
			}
			stk[hi++] = {cur, e&1};
		}
		if (hi >= 2 && stk[hi-2].second == stk[hi-1].second) {
			array<int, 2> a = stk[hi-2].first, b = stk[hi-1].first, c = stk[lo].first;
			if (stk[hi-1].second) swap(a, c);
			hi -= 2;
			nxt[a[1]] = b[0];
			nxt[b[1]] = c[0];
			stk[lo].first = {a[0], c[1]};
		}
		if (hi - lo != 2) {
			cout << "NO" << '\n';
			exit(0);
		}
		if (stk[lo].second) {
			swap(stk[lo], stk[lo+1]);
		}
		nxt[stk[lo+1].first[1]] = cur_path;
		nxt[stk[lo].first[1]] = stk[lo+1].first[0];
		cur_path = stk[lo].first[0];
	}

	cout << "YES" << '\n';
	for (int i = cur_path; i != -1; i = nxt[i]) {
		cout << cards[i][0] << ' ' << cards[i][1] << '\n';
	}

	return 0;
}