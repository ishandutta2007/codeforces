#include<bits/stdc++.h>
namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<string> G(N);
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}
	int cnt_black = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt_black += G[i][j] == 'B';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j] == 'B') {
				vector<vector<bool>> vis(N, vector<bool>(M));
				int cnt = 0;
				for (int x = i; x < N; x++) {
					if (G[x][j] != 'B') break;
					for (int y = j; y < M; y++) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
					for (int y = j; y >= 0; y--) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
				}
				for (int x = i; x >= 0; x--) {
					if (G[x][j] != 'B') break;
					for (int y = j; y < M; y++) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
					for (int y = j; y >= 0; y--) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
				}
				for (int y = j; y < M; y++) {
					if (G[i][y] != 'B') break;
					for (int x = i; x < N; x++) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
					for (int x = i; x >= 0; x--) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
				}
				for (int y = j; y >= 0; y--) {
					if (G[i][y] != 'B') break;
					for (int x = i; x < N; x++) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
					for (int x = i; x >= 0; x--) {
						if (G[x][y] != 'B') break;
						vis[x][y] = true;
					}
				}
				for (int x = 0; x < N; x++) {
					for (int y = 0; y < M; y++) {
						if (G[x][y] == 'B' && !vis[x][y]) {
							cout << "NO" << '\n';
							exit(0);
						}
					}
				}
			}
		}
	}

	cout << "YES" << '\n';

	return 0;
}