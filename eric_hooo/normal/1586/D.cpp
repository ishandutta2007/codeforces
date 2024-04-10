#include <bits/stdc++.h>
using namespace std;

int a[110], tmp[110];
int n;
vector <int> up, dw;

int Query() {
	printf("?");
	for (int i = 1; i <= n; i++) {
		printf(" %d", tmp[i]);
	}
	printf("\n");
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

void Answer() {
	printf("!");
	for (int i = 1; i <= n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		tmp[i] = 1;
	}
	for (int val = 2; val <= n; val++) {
		tmp[n] = val;
		int p = Query();
		if (p == 0) break;
		up.push_back(p);
	}
	tmp[n] = 1;
	for (int val = 2; val <= n; val++) {
		for (int i = 1; i < n; i++) {
			tmp[i] = val;
		}
		int p = Query();
		if (p == 0) break;
		dw.push_back(p);
	}
	a[n] = dw.size() + 1;
	reverse(dw.begin(), dw.end());
	for (int i = 0; i < dw.size(); i++) {
		a[dw[i]] = i + 1;
	}
	for (int i = 0; i < up.size(); i++) {
		a[up[i]] = dw.size() + 2 + i;
	}
	Answer();
	return 0;
}