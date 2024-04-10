#include <bits/stdc++.h>
using namespace std;

vector <int> solve(int n) {
	vector <int> V;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				V.push_back(i * 8 + j);
			}
		}else {
			for (int j = 7; j >= 0; j--) {
				V.push_back(i * 8 + j);
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			V.push_back(7 * 8 + i);
			V.push_back(6 * 8 + i);
		}else {
			V.push_back(6 * 8 + i);
			V.push_back(7 * 8 + i);
		}
	}
	if (n == 64) {
		return V;
	}
	if (n == 62) {
		V.pop_back();
		V.pop_back();
		V.pop_back();
		V.pop_back();
		V.pop_back();
		V.push_back(6 * 8 + 7);
		V.push_back(6 * 8 + 6);
		V.push_back(7 * 8 + 6);
		V.push_back(63);
		return V;
	}
	vector <int> VV;
	for (int i = 0; i < 64; i++) {
		VV.push_back(V[i]);
		int x = V[i] / 8, y = V[i] % 8;
		if (i + 1 == n && (x == 7 || y == 7)) {
			VV.push_back(63);
			return VV;
		}
		if (i + 2 == n) {
			if (x % 8 == 7) {
				VV.push_back(x * 8 + 6);
				VV.push_back(x * 8 + 7);
			}else if (y == 7) {
				VV.push_back(6 * 8 + y);
				VV.push_back(7 * 8 + y);
			}else {
				if (x < 6) {
					VV.push_back(7 * 8 + y);
					VV.push_back(63);
				}else {
					VV.push_back(x * 8 + 7);
					VV.push_back(63);
				}
			}
			return VV;
		}
	}
	assert(false);
}

int main() {
	for (int i = 2; i <= 63; i++) {
		auto V = solve(i);
		assert(V.size() == i + 1);
		assert(V[0] == 0);
		assert(V.back() == 63);
		bool used[64];
		for (int j = 0; j < 64; j++)
			used[j] = false;
		// printf("%d\n", i);
		// for (auto x: V) {
		// 	printf("%d ", x);
		// }
		// printf("\n");
		for (auto x: V) {
			if (used[x]) {
				assert(false);
			}
			used[x] = true;
		}
		for (int j = 0; j < i; j++) {
			assert(V[j] % 8 == V[j + 1] % 8 || V[j] / 8 == V[j + 1] / 8);
		}
	}
	int n;
	scanf("%d", &n);
	auto V = solve(n);
	for (int i = 0; i <= n; i++) {
		printf("%c%d", 'a' + (V[i] / 8), 1 + V[i] % 8);
		if (i < n)
			printf(" ");
		else
			printf("\n");
	}
}