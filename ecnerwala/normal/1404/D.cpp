#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	if (N % 2 == 0) {
		cout << "First" << '\n';
		for (int i = 0; i < 2*N; i++) {
			cout << i%N+1 << " \n"[i+1==2*N];
		}
		cout << flush;
		exit(0);
	} else {
		cout << "Second" << '\n' << flush;
		vector<int> P(2*N);
		for (int i = 0; i < 2*N; i++) {
			cin >> P[i];
			P[i]--;
		}
		vector<int> pairs(N, 0);
		for (int i = 0; i < 2*N; i++) {
			pairs[P[i]] ^= i;
		}

		vector<bool> take(2*N);
		vector<bool> vis(N);
		for (int st = 0; st < N; st++) {
			if (vis[st]) continue;
			for (int cur = st; !vis[cur%N]; ) {
				take[cur] = true;
				vis[cur%N] = true;
				cur ^= pairs[P[cur]];
				cur = (cur + N) % (2*N);
			}
		}

		int tot = 0;
		for (int i = 0; i < 2*N; i++) {
			if (take[i]) {
				tot += i+1;
				tot %= (2*N);
			}
		}
		assert(tot == 0 || tot == N);
		if (tot == N) {
			for (int i = 0; i < 2*N; i++) take[i] = !take[i];
		}
		for (int i = 0; i < 2*N; i++) {
			if (take[i]) {
				cout << i+1 << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}

// 0,1,2,3 is 0 mod 4
// (3,1) and (2,0) is winning for P1

// 0,1,2,3,4,5 mod 6