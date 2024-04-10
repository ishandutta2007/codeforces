#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010];
vector <int> odd, even;
vector <int> p, q;
int s1[1 << 14], s2[1 << 14];
int tmp[30000000];

void Solve(vector <int> &a) {
	int n = a.size();
	int n1 = min(n, 14), n2 = n - n1;
	for (int mask = 0; mask < (1 << n1); mask++) {
		for (int i = 0; i < n1; i++) {
			if (mask >> i & 1) s1[mask] += a[i];
		}
	}
	for (int mask = 0; mask < (1 << n2); mask++) {
		for (int i = 0; i < n2; i++) {
			if (mask >> i & 1) s2[mask] += a[n1 + i];
		}
	}
	int P = -1, Q = -1;
	for (int k = 1; 2 * k <= n; k++) {
		memset(tmp, -1, sizeof(tmp));
		int mask = (1 << k) - 1;
		while (mask < (1 << n)) {
			int sum = s1[mask & (1 << n1) - 1] + s2[mask >> n1];
			if (tmp[sum] != -1) {
				P = mask, Q = tmp[sum];
				goto END;
			}
			tmp[sum] = mask;
			int x = mask & -mask, y = mask + x;
			mask = ((mask & ~y) / x >> 1) | y;
		}
	}
	END:;
	if (P == -1) return ;
	int tmp = P & Q; P ^= tmp, Q ^= tmp;
	for (int i = 0; i < n; i++) {
		if (P >> i & 1) p.push_back(a[i]);
		if (Q >> i & 1) q.push_back(a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if ((P >> i & 1) || (Q >> i & 1)) a.erase(a.begin() + i);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	if (even.size()) {
		int a, b, c;
		if (even.size() >= 3) a = even[0], b = even[1], c = even[2], even.erase(even.begin(), even.begin() + 3);
		else if (odd.size() >= 2) a = even[0], b = odd[0], c = odd[1], odd.erase(odd.begin(), odd.begin() + 2), even.erase(even.begin());
		else {
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		int x = a - c + b >> 1;
		printf("%d %d %d ", x, b - x, c - b + x);
		int lst = c - b + x;
		for (auto it : even) {
			printf("%d ", lst = it - lst);
		}
		for (auto it : odd) {
			printf("%d ", lst = it - lst);
		}
		printf("\n");
		return 0;
	}
	vector <int> spc;
	while (odd.size() && spc.size() < 27) spc.push_back(odd.back()), odd.pop_back();
	Solve(spc);
	if (!p.size()) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int lst = 0;
	printf("%d ", lst);
	printf("%d ", lst = q[0] - lst);
	for (int i = 1; i < p.size(); i++) {
		printf("%d ", lst = p[i] - lst);
		printf("%d ", lst = q[i] - lst);
	}
	for (auto it : spc) {
		printf("%d ", lst = it - lst);
	}
	for (auto it : odd) {
		printf("%d ", lst = it - lst);
	}
	printf("\n");
	return 0;
}