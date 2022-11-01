#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n, d[N], A[N], B[N], ans[N];

typedef pair<int, int> PII;

PII e[N];

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", A + i, B + i);
		d[A[i]]++, d[B[i]]++;
	}
	for (int i = 1; i < n; i++) {
		e[i].first = min(d[A[i]], d[B[i]]);
		e[i].second = i;
	}
	sort(e + 1, e + n);
	for (int i = 1; i < n; i++) ans[e[i].second] = i - 1;
	for (int i = 1; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}