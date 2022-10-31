#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

#define maxn 100010

long long n, m, k, a[maxn], l[maxn], r[maxn], d[maxn], x[maxn], y[maxn], c[maxn], cc[maxn];

int main() {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> l[i] >> r[i] >> d[i], l[i]--;
	for (int i=0; i<k; i++) cin >> x[i] >> y[i], x[i]--;
	for (int i=0; i<k; i++) c[x[i]]++, c[y[i]]--;
	for (int i=0, now=0; i<m; i++) now+=c[i], cc[l[i]]+=now*d[i], cc[r[i]]-=now*d[i];
	for (long long i=0, now=0; i<n; i++) {
		now+=cc[i];
		cout << a[i]+now << ' ';
	}
	return 0;
}