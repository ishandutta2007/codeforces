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
	int X, Y; cin >> X >> Y;
	vector<string> G(X);
	for (int i = 0; i < X; i++) {
		cin >> G[i];
	}

	const int V = X * Y;
	vector<int> nxt(V);
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			int ni = i, nj = j;
			switch (G[i][j]) {
				case 'U': ni += 2; break;
				case 'D': ni -= 2; break;
				case 'L': nj += 2; break;
				case 'R': nj -= 2; break;
			}
			if (0 <= ni && ni < X && 0 <= nj && nj < Y) {
				nxt[i*Y+j] = ni*Y+nj;
			} else {
				nxt[i*Y+j] = -1;
			}
		}
	}

	vector<vector<int>> ch(V);
	for (int i = 0; i < V; i++) {
		if (nxt[i] == -1) continue;
		ch[nxt[i]].push_back(i);
	}

	vector<pair<int, int>> bounds(V);
	array<int, 2> curInd({0,0});
	for (int i = 0; i < V; i++) {
		if (nxt[i] != -1) continue;
		bool z = (i / Y + i % Y) & 1;
		std::y_combinator([&](auto self, int cur) -> void {
			bounds[cur].first = curInd[z];
			curInd[z]++;
			for (int c : ch[cur]) self(c);
			bounds[cur].second = curInd[z];
		})(i);
	}

	int A = curInd[0];
	//int B = curInd[1];
	vector<vector<pair<int, int>>> inserts(A+1);
	vector<vector<pair<int, int>>> deletes(A+1);

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			if ((x + y) & 1) continue;
			int nx = x, ny = y;
			switch (G[x][y]) {
				case 'U': nx++; break;
				case 'D': nx--; break;
				case 'L': ny++; break;
				case 'R': ny--; break;
			}
			assert(0 <= nx && nx < X && 0 <= ny && ny < Y);
			int a = x * Y + y;
			int b = nx * Y + ny;
			inserts[bounds[a].first].push_back(bounds[b]);
			deletes[bounds[a].second].push_back(bounds[b]);
		}
	}

	const int S = 1 << 18;
	vector<int> seg(2*S);
	vector<int> lazy(2*S);
	auto update_node = [&](int a) {
		if (lazy[a]) seg[a] = 1 << (__builtin_clz(a) - __builtin_clz(S));
		else if (a >= S) seg[a] = 0;
		else seg[a] = seg[2*a] + seg[2*a+1];
	};
	auto update_all = [&](int a) {
		for(; a; a >>= 1) update_node(a);
	};
	auto do_update = [&](int l, int r, int d) {
		for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
			if (a & 1) {
				lazy[a]+=d;
				update_node(a);
				a++;
			}
			if (b & 1) {
				--b;
				lazy[b]+=d;
				update_node(b);
			}
		}
		update_all(S+l);
		update_all(S+r-1);
	};

	int64_t ans = 0;
	for (int x = 0; x < A; x++) {
		for (auto it : deletes[x]) {
			do_update(it.first, it.second, -1);
		}
		for (auto it : inserts[x]) {
			do_update(it.first, it.second, +1);
		}
		ans += seg[1];
	}
	cout << ans << '\n';

	return 0;
}