#include<bits/stdc++.h>
using namespace std;

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

[[noreturn]] void FAIL() {
	cout << -1 << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	auto get = [&](vector<int>& a, int i, int j, int k) -> int& {
		return a[(i * M + j) * K + k];
	};

	vector<int> A(N*M*K, -1);
	vector<vector<int>> constraints(6, A);
	auto& xinc = constraints[0];
	auto& xdec = constraints[1];
	auto& yinc = constraints[2];
	auto& ydec = constraints[3];
	auto& zinc = constraints[4];
	auto& zdec = constraints[5];

	for (int j = 0; j < M; j++) {
		for (int k = 0; k < K; k++) {
			cin >> get(xinc,0,j,k);
		}
	}
	for (int j = 0; j < M; j++) {
		for (int k = 0; k < K; k++) {
			cin >> get(xdec,N-1,j,k);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			cin >> get(yinc,i,0,k);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			cin >> get(ydec,i,M-1,k);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> get(zinc,i,j,0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> get(zdec,i,j,K-1);
		}
	}

	auto checkSquare = std::y_combinator([&](auto self, int i, int j, int k) -> void {
		auto shouldClear = [&]() -> bool {
			if (get(A,i,j,k) == 0) return true;
			int lastSeen = -1;
			for (vector<int>& a : constraints) {
				int v = get(a,i,j,k);
				if (v == 0) return true;
				else if (v == -1) continue;
				else if (lastSeen == -1) lastSeen = v;
				else if (lastSeen != v) return true;
			}
			return false;
		};
		if (shouldClear()) {
			get(A,i,j,k) = 0;
			// push each thing
			auto tryClear = [&](vector<int>& v, int ni, int nj, int nk) {
				int& curVal = get(v,i,j,k);
				if (curVal == -1) return;
				if (!(0 <= ni && ni < N && 0 <= nj && nj < M && 0 <= nk && nk < K)) {
					if (curVal == 0) {
						return;
					} else {
						FAIL();
					}
				}
				int& nxtVal = get(v,ni,nj,nk);
				assert(nxtVal == -1 || nxtVal == curVal);
				if (nxtVal == curVal) return;
				nxtVal = curVal;
				curVal = -1;
				self(ni, nj, nk);
			};
			tryClear(xinc, i+1, j, k);
			tryClear(xdec, i-1, j, k);
			tryClear(yinc, i, j+1, k);
			tryClear(ydec, i, j-1, k);
			tryClear(zinc, i, j, k+1);
			tryClear(zdec, i, j, k-1);
		}
	});

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < K; k++) {
				if (i == 0 || i == N-1 || j == 0 || j == M-1 || k == 0 || k == K-1) {
					checkSquare(i, j, k);
				}
			}
		}
	}


	for (int i = 0; i < N; i++) {
		if (i) cout << '\n';
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < K; k++) {
				int& v = get(A,i,j,k);
				if (v == -1) {
					v = 0;
					for (vector<int>& vec : constraints) {
						v = max(v, get(vec,i,j,k));
					}
				}
				cout << v << " \n"[k+1==M];
			}
		}
	}

	return 0;
}