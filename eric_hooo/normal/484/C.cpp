#include <bits/stdc++.h>
using namespace std;

typedef vector <int> per;

vector <int> getI(int n) {
	vector <int> a;
	for (int i = 0; i < n; i++) {
		a.push_back(i);
	}
	return a;
}

per operator * (const per &a, const per &b) {
	per res(a.size());
	for (int i = 0; i < a.size(); i++) {
		res[i] = b[a[i]];
	}
	return res;
}

per get_inv(const per &a) {
	per b(a.size());
	for (int i = 0; i < a.size(); i++) {
		b[a[i]] = i;
	}
	return b;
}

char s[1000010];

int main () {
	scanf("%s", s);
	int n = strlen(s);
	per P = getI(n);
	int q; scanf("%d", &q);
	while (q--) {
		int k, d; scanf("%d%d", &k, &d);
		per trans;
		for (int i = 0; i < n; i++) {
			int x = i < k ? i % d * (k / d) + min(i % d, k % d) + i / d : i;
			trans.push_back(x ? x - 1 : n - 1);
		}
		int T = n - k + 1;
		while (T) {
			if (T & 1) P = P * trans;
			trans = trans * trans, T >>= 1;
		}
		trans.clear();
		for (int i = 0; i < n; i++) {
			trans.push_back((i - k + 1 + n + n) % n);
		}
		P = P * trans;
		per Q = get_inv(P);
		for (int i = 0; i < n; i++) {
			printf("%c", s[Q[i]]);
		}
		printf("\n");
	}
	return 0;
}