#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int T, N;
int A[MAXN];
bool used[MAXN];
int pre[MAXN], rep[MAXN];
vector<vector<int> > ans;

int getk(int n) {
	int k = 1;
	while (k * (k + 1) / 2 <= n)
		++k;
	return k - 1;
}

vector<int> lis() {
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (used[A[i]])
			continue;
		auto it = lower_bound(v.begin(), v.end(), A[i]);
		pre[A[i]] = (it == v.begin() ? -1 : it[-1]);
		if (it == v.end())
			rep[A[i]] = -1, v.push_back(A[i]);
		else
			rep[A[i]] = *it, *it = A[i];
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		memset(used, 0, sizeof used);
		ans.clear();

		int total = 0;
		while (total < N) {
			int k = getk(N - total);
			auto v = lis();
			if (v.size() <= k) {
				// dilworth: min chain decomposition <= k
				for (int x : v) {
					// chains thru rep[]
					vector<int> cur;
					for (int j = x; j != -1; j = rep[j])
						cur.push_back(j);
					reverse(cur.begin(), cur.end());
					ans.push_back(move(cur));
				}
				total = N;
			}
			else {
				// dilworth: max antichain > k
				vector<int> cur;
				for (int j = v.back(); j != -1; j = pre[j])
					cur.push_back(j), used[j] = true;
				reverse(cur.begin(), cur.end());
				total += cur.size();
				ans.push_back(move(cur));
			}
		}

		cout << ans.size() << '\n';
		for (auto& seq : ans) {
			cout << seq.size();
			for (int x : seq)
				cout << ' ' << x;
			cout << '\n';
		}
	}

	cout.flush();
	return 0;
}