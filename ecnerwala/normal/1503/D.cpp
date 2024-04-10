#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<array<int, 2>> A(N);
	for (auto& a : A) {
		cin >> a[0] >> a[1];
	}

	sort(A.begin(), A.end(), [&](const auto& a, const auto& b) { return abs(a[1] - a[0]) < abs(b[1] - b[0]); });

	array<int, 2> base1 = A[0];
	array<int, 2> base2 = A[0]; swap(base2[0], base2[1]);

	int base1_flip = base1[0] > base1[1];
	sort(base1.begin(), base1.end());

	int base2_flip = base2[0] > base2[1];
	sort(base2.begin(), base2.end());

	reverse(base2.begin(), base2.end());

	assert(base1_flip + base2_flip == 1); // base1_flip is if base1 is < and base2 is >

	vector<array<int, 2>> cur_stack; cur_stack.reserve(N);
	for (int i = 1; i < N; i++) {
		//cerr << "start " << i << ' ' << A[i][0] << '-' << A[i][1] << '\n';
		//cerr << base1[0] << '-' << base1[1] << ' ' << base1_flip << '\n';
		//cerr << base2[0] << '-' << base2[1] << ' ' << base2_flip << '\n';
		int vlo = min(A[i][0], A[i][1]);
		int vhi = max(A[i][0], A[i][1]);
		bool can1 = (vlo < base1[0] && base1[1] < vhi);
		bool can2 = (vlo < base2[0] && base2[1] < vhi);
		if (!can1 && !can2) {
			cout << -1 << '\n';
			exit(0);
		}
		if ((cur_stack.empty() && can1 && can2) ||
			(!cur_stack.empty() && vlo < min(cur_stack.back()[0], cur_stack.back()[1]) && max(cur_stack.back()[0], cur_stack.back()[1]) < vhi)) {
			cur_stack.push_back(A[i]);
			continue;
		}

		// We can skip a prefix of the stack
		int idx = 0;
		while (idx < int(cur_stack.size()) && (vlo < min(cur_stack[idx][0], cur_stack[idx][1]) && max(cur_stack[idx][0], cur_stack[idx][1]) < vhi)) idx++;
		assert(cur_stack.empty() || idx < int(cur_stack.size()));

		if (!can1 || !can2) {
			assert(can1 || can2);
			if (can2) {
				swap(base1, base2);
				swap(can1, can2);
				swap(base1_flip, base2_flip);
			}
			assert(can1);
			assert(!can2);
		} else {
			assert(can1 && can2);
			assert(!cur_stack.empty());
			base1_flip = base2_flip = min(base1_flip, base2_flip);
		}

		base1 = A[i];
		if (base1[0] > base1[1]) base1_flip++;
		else base2_flip++;
		sort(base1.begin(), base1.end());

		for (; idx < int(cur_stack.size()); idx++) {
			base2 = cur_stack[idx];
			if (base2[0] > base2[1]) base2_flip++;
			else base1_flip++;
			sort(base2.begin(), base2.end());
		}

		cur_stack.clear();
	}

	cout << min(base1_flip, base2_flip) << '\n';

	return 0;
}