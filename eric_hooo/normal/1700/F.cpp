#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000;

int n;
priority_queue <int> L;
priority_queue <int, vector <int>, greater <int> > R;
int LL, RR;
long long base;
int S;
int a[4][200010];

void Merge(int f, int d, int g) {
	if (f) {
		assert(!g);
		LL += d, RR += d, d = -d, swap(f, g);
	}
	assert(g == 1);
	if (d == 1) {
		int x = R.top() + RR; R.pop();
		RR++;
		R.push(x - RR);
	} else {
		int x = L.top() + LL; L.pop();
		LL--;
		L.push(x - LL);
	}
}

void Shift(int t) {
	S += t & 2 ? -1 : 1;
	Merge(t & 1 ? 0 : 1, t & 2 ? -1 : 1, t & 1 ? 1 : 0);
}

void Apply(int x) {
	if (L.top() + LL <= x && x <= R.top() + RR) {
		L.push(x - LL), R.push(x - RR);
	} else if (x < L.top() + LL) {
		base += abs(L.top() + LL - x);
		L.push(x - LL), L.push(x - LL);
		R.push(L.top() + LL - RR), L.pop();
	} else {
		base += abs(R.top() + RR - x);
		R.push(x - RR), R.push(x - RR);
		L.push(R.top() + RR - LL), R.pop();
	}
}

int main() {
	scanf("%d", &n);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[j][i]);
		}
	}
	base = 0; for (int i = 0; i < n * 2 + 10; i++) L.push(0), R.push(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[j][i]) {
				Shift(j);
			}
		}
		Apply(0), Apply(S);
	}
	if (S != 0) printf("-1\n");
	else printf("%lld\n", base);
	return 0;
}