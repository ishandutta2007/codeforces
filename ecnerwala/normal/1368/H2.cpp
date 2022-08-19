#include<bits/stdc++.h>

struct count_seg {
	struct node {
		std::array<int, 2> c;
		bool flip = false;
	};
	std::vector<node> seg;
	count_seg() : seg() {}
	explicit count_seg(int N) : seg(2*N) {}
	std::array<int, 2> query_all() { return seg[1].c; }
	void update_node(int a) {
		int N = int(seg.size())>>1;
		if (a >= N) {
			seg[a].c[0] = 0, seg[a].c[1] = 1;
		} else {
			seg[a].c[0] = seg[2*a].c[0] + seg[2*a+1].c[0];
			seg[a].c[1] = seg[2*a].c[1] + seg[2*a+1].c[1];
		}
		if (seg[a].flip) std::swap(seg[a].c[0], seg[a].c[1]);
	}
	void flip_node(int a) {
		seg[a].flip ^= 1;
		std::swap(seg[a].c[0], seg[a].c[1]);
	}
	void flip_leaf_lazy(int l) {
		int N = int(seg.size())>>1;
		seg[N+l].flip ^= 1;
	}
	void flip_range(int l, int r) {
		int N = int(seg.size())>>1;
		for (int a = l+N, b = r+N; a < b; a >>= 1, b >>= 1) {
			if (a & 1) flip_node(a++);
			if (b & 1) flip_node(--b);
		}
		for (int a = l+N; a; a >>= 1) update_node(a);
		for (int b = r+N-1; b; b >>= 1) update_node(b);
	}
	void update_all() {
		for (int i = int(seg.size())-1; i; --i) update_node(i);
	}
};

struct big_seg {
	struct mat {
		std::array<std::array<std::array<int, 2>, 2>, 2> v;
		friend mat operator * (const mat& a, const mat& b) {
			mat res;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					for (int z = 0; z < 2; z++) {
						res.v[i][j][z] = std::min(a.v[i][j][0] + b.v[i][j][z], a.v[i][j][1] + b.v[!i][!j][!z]);
					}
				}
			}
			return res;
		}
		int eval(std::array<int, 2> st, std::array<int, 2> en) const {
			int res = st[0] + v[0][0][0] + en[0];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					res = std::min(res, st[i] + v[i][i][i^j] + en[j]);
				}
			}
			return res;
		}
	};

	struct node {
		mat m;
		std::array<bool, 2> flip = {false, false};
	};

	int N, M;
	std::vector<node> seg;
	big_seg() : N(0), seg() {}
	big_seg(int N_, int M_) : N(N_), M(M_), seg() {
		int S = 1; while (S < N) S *= 2;
		seg.resize(2*S);
	}
	mat query_all() { return seg[1].m; }
	void update_node(int a) {
		int S = int(seg.size())>>1;
		if (a >= S) {
			if (a-S < N) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						seg[a].m.v[i][j][0] = i+j;
						seg[a].m.v[i][j][1] = i+j+M;
					}
				}
			} else {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						seg[a].m.v[i][j][0] = 0;
						seg[a].m.v[i][j][1] = 0+M;
					}
				}
			}
		} else {
			seg[a].m = seg[2*a].m * seg[2*a+1].m;
		}
		if (seg[a].flip[0]) {
			swap(seg[a].m.v[0], seg[a].m.v[1]);
		}
		if (seg[a].flip[1]) {
			swap(seg[a].m.v[0][0], seg[a].m.v[0][1]);
			swap(seg[a].m.v[1][0], seg[a].m.v[1][1]);
		}
	}
	void flip_node(int a, bool z) {
		seg[a].flip[z] ^= 1;
		if (z == 0) {
			swap(seg[a].m.v[0], seg[a].m.v[1]);
		} else if (z == 1) {
			swap(seg[a].m.v[0][0], seg[a].m.v[0][1]);
			swap(seg[a].m.v[1][0], seg[a].m.v[1][1]);
		} else assert(false);
	}
	void flip_leaf_lazy(int l, bool z) {
		int S = int(seg.size())>>1;
		seg[S+l].flip[z] ^= 1;
	}
	void flip_range(int l, int r, bool z) {
		int S = int(seg.size())>>1;
		for (int a = l+S, b = r+S; a < b; a >>= 1, b >>= 1) {
			if (a & 1) flip_node(a++, z);
			if (b & 1) flip_node(--b, z);
		}
		for (int a = l+S; a; a >>= 1) update_node(a);
		for (int b = r+S-1; b; b >>= 1) update_node(b);
	}
	void update_all() {
		for (int i = int(seg.size())-1; i; --i) update_node(i);
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	array<int, 2> N; int Q; cin >> N[0] >> N[1] >> Q;
	array<array<count_seg, 2>, 2> count_segs;
	array<big_seg, 2> big_segs;
	for (int a = 0; a < 2; a++) {
		big_segs[a] = big_seg(N[a], N[!a]);
		for (int b = 0; b < 2; b++) {
			count_segs[a][b] = count_seg(N[a]);
			string S; cin >> S;
			assert(int(S.size()) == N[a]);
			for (int i = 0; i < N[a]; i++) {
				if (S[i] == 'R') {
					count_segs[a][b].flip_leaf_lazy(i);
					big_segs[a].flip_leaf_lazy(i, b);
				}
			}
			count_segs[a][b].update_all();
		}
		big_segs[a].update_all();
	}
	auto query = [&]() -> int {
		int ans = 2*N[0]+2*N[1];
		for (int z = 0; z < 2; z++) {
			int cnd = big_segs[!z].query_all().eval(count_segs[z][0].query_all(), count_segs[z][1].query_all());
			ans = min(ans, cnd);
		}
		return ans;
	};

	cout << query() << '\n';
	for (int q = 0; q < Q; q++) {
		char side; int l, r; cin >> side >> l >> r; l--;
		bool dim, z;
		switch (side) {
			case 'L': dim = 0, z = 0; break;
			case 'R': dim = 0, z = 1; break;
			case 'U': dim = 1, z = 0; break;
			case 'D': dim = 1, z = 1; break;
			default: assert(false);
		}
		assert(0 <= l && l < r && r <= N[dim]);
		count_segs[dim][z].flip_range(l, r);
		big_segs[dim].flip_range(l, r, z);
		cout << query() << '\n';
	}

	return 0;
}