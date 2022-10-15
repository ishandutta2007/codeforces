#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000

int N;
int beaver_index[MAXN + 1]; // indices ID's, values are indices of beavers
int beaver_id[MAXN + 1]; // map an index to an id
int fenwick[MAXN + 1]; // get #(beavershave) for range [1, n]

int query(int n) {
	// [1, n]
	int ret = 0;
	for (int i = n; i > 0; i -= i & -i) {
		ret += fenwick[i];
		if (i != n && beaver_index[i] >= beaver_index[i + 1]) {
			ret++;
		}
	}
	return ret;
}

int update(int ind, int x) {
	// change the index of the beaver with ID ind to x
	int prev = beaver_index[ind];
	beaver_index[ind] = x;
	int change_left = 0, change_right = 0;
	if (ind > 0 && x <= beaver_index[ind - 1]) {
		change_left++;
	}
	if (ind > 0 && prev <= beaver_index[ind - 1]) { // left -1, right 1
		change_left--;
	}
	if (ind <= N && x >= beaver_index[ind + 1]) {
		change_right++;
	}
	if (ind <= N && prev >= beaver_index[ind + 1]) {
		change_right--;
	}

	for (int fen_ind = ind; fen_ind <= N; fen_ind += fen_ind & -fen_ind) {
		int lo = fen_ind - (fen_ind & -fen_ind);
		if (lo < ind - 1) {
			fenwick[fen_ind] += change_left;
		}
		if (fen_ind >= ind + 1) {
			fenwick[fen_ind] += change_right;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("331B2.in", "r", stdin);

	cin >> N;

	// initialize fenwick and beavers to anything consistent
	for (int i = 1; i <= N; i++) {
		fenwick[i] = 0;
		beaver_index[i] = i;
		beaver_id[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		beaver_id[i] = temp;
		update(temp, i);
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int P, X, Y;
		cin >> P >> X >> Y;

		/* debug
		for (int i = 0; i <= N; i++) {
			cout << beaver_index[i] << ' ' << fenwick[i] << '|';
		}
		cout << '\n';
		*/

		if (P == 2) {
			update(beaver_id[X], Y);
			update(beaver_id[Y], X);
			int temp = beaver_id[X];
			beaver_id[X] = beaver_id[Y];
			beaver_id[Y] = temp;
		}
		else if (P == 1) {
			int result = query(Y) - query(X - 1);
			if (beaver_index[X] <= beaver_index[X - 1]) {
				result--;
			}
			cout << result + 1 << '\n';
		}
		else {
			throw new domain_error("bad input of query type");
		}
	}

	cout.flush();
	return 0;
}