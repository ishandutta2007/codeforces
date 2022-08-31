#include <bits/stdc++.h>

[[noreturn]] void FAIL() {
	std::cout << "NO" << '\n';
	exit(0);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int64_t C; cin >> N >> C;
	vector<int64_t> W(N-2); for (auto& w : W) cin >> w;
	W.push_back(W.back());

	// there are 2 types of nontrivial events:
	//   either we take the full range at a particular interval, or we take a full range at a location
	// Either way, we can store it by the original loc

	vector<bool> can_full(N-1);
	vector<int> prv(N-1, -1);
	vector<int64_t> prv_val(N-1);

	int cur_sign = 1;
	int64_t cur_plus = 0;
	deque<pair<array<int64_t, 2>, int>> cur_poss;

	auto transform = [&](pair<array<int64_t, 2>, int> r) -> pair<array<int64_t, 2>, int> {
		if (cur_sign == -1) {
			swap(r.first[0], r.first[1]);
			r.first[0] *= -1;
			r.first[1] *= -1;
		}
		r.first[0] += cur_plus;
		r.first[1] += cur_plus;
		return r;
	};
	auto untransform = [&](pair<array<int64_t, 2>, int> r) -> pair<array<int64_t, 2>, int> {
		r.first[0] -= cur_plus;
		r.first[1] -= cur_plus;
		if (cur_sign == -1) {
			swap(r.first[0], r.first[1]);
			r.first[0] *= -1;
			r.first[1] *= -1;
		}
		return r;
	};
	auto get_front = [&]() -> pair<array<int64_t, 2>, int> {
		return transform((cur_sign == -1 ? cur_poss.back() : cur_poss.front()));
	};
	auto pop_front = [&]() -> void {
		if (cur_sign == -1) cur_poss.pop_back();
		else cur_poss.pop_front();
	};
	auto set_front = [&](pair<array<int64_t, 2>, int> v) -> void {
		v = untransform(v);
		if (cur_sign == -1) cur_poss.back() = v;
		else cur_poss.front() = v;
	};
	auto push_front = [&](pair<array<int64_t, 2>, int> v) -> void {
		v = untransform(v);
		if (cur_sign == -1) cur_poss.push_back(v);
		else cur_poss.push_front(v);
	};
	auto get_back = [&]() -> pair<array<int64_t, 2>, int> {
		return transform((cur_sign == -1 ? cur_poss.front() : cur_poss.back()));
	};
	auto pop_back = [&]() -> void {
		if (cur_sign == -1) cur_poss.pop_front();
		else cur_poss.pop_back();
	};
	auto set_back = [&](pair<array<int64_t, 2>, int> v) -> void {
		v = untransform(v);
		if (cur_sign == -1) cur_poss.front() = v;
		else cur_poss.back() = v;
	};
	auto push_back = [&](pair<array<int64_t, 2>, int> v) -> void {
		v = untransform(v);
		if (cur_sign == -1) cur_poss.push_front(v);
		else cur_poss.push_back(v);
	};
	auto empty = [&]() -> bool {
		return cur_poss.empty();
	};

	push_back({{0, W[0]}, -1}); // inclusive interval
	for (int i = 0; i < N-1; i++) {
		// first, trim the high and low
		while (!empty() && get_back().first[0] > W[i]) {
			pop_back();
		}
		if (!empty() && get_back().first[1] > W[i]) {
			auto n = get_back();
			n.first[1] = W[i];
			set_back(n);
		}
		while (!empty() && get_front().first[1] < 0) {
			pop_front();
		}
		if (!empty() && get_front().first[0] < 0) {
			auto n = get_front();
			n.first[0] = 0;
			set_front(n);
		}

		if (empty()) {
			FAIL();
		}

		if (get_back().first[1] == W[i]) {
			can_full[i] = true;
			prv[i] = get_back().second;
			prv_val[i] = W[i];
			cur_sign = 1;
			cur_plus = 0;
			cur_poss.clear();
			push_back({{0, W[i]}, i});
		} else {
			// pick something arbitrary to be +
			if (get_front().first[0] != 0) {
				prv_val[i] = get_front().first[0];
				prv[i] = get_front().second;
				push_front({{0,0},i});
			}

			assert(prv[i] == -1 || (0 < prv_val[i] && prv_val[i] < W[i]));

			cur_sign = -cur_sign;
			cur_plus = W[i] - cur_plus;
		}
	}

	assert(can_full[0]);
	assert(can_full[N-2]);

	vector<int64_t> H(N);
	H[N-1] = 0;
	int delta_sign = 1;
	for (int cur = N-2; cur != -1; ) {
		int p = prv[cur];
		int64_t v = prv_val[cur];
		delta_sign *= -1;
		H[cur] = H[cur+1] + delta_sign * v;
		while (--cur != p) {
			v = W[cur] - v;
			H[cur] = H[cur+1] + delta_sign * v;
		}
	}

	for (int i = 0; i < N-2; i++) {
		assert(max({H[i], H[i+1], H[i+2]}) - min({H[i], H[i+1], H[i+2]}) == W[i]);
	}
	int64_t min_H = *min_element(H.begin(), H.end());
	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		H[i] -= min_H;
		cout << H[i] << " \n"[i+1==N];
	}

	return 0;
}