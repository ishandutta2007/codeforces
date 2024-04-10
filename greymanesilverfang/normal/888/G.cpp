// Problem: Given a complete graph, weight of edge (i, j) = a_i xor a_j. Build MST.

#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std; 
int a[200000]; ll INF = 1e12;
inline bool comp_bit(int x, int y) { return !!(x & y); }
inline int binsearch(int l, int r, int depth) { return (upper_bound(a + l, a + r, 1 << depth, comp_bit) - a); }

ll connect(int depth, int l1, int r1, int l2, int r2) {
	if (l1 == r1 || l2 == r2) return INF;
	if (a[l1] == a[r1 - 1] && a[l2] == a[r2 - 1]) return a[l1] ^ a[l2];
	int mid1 = binsearch(l1, r1, depth), mid2 = binsearch(l2, r2, depth);
	if (mid1 == l1 && mid2 == r2 || mid1 == r1 && mid2 == l2)
		return connect(depth - 1, l1, r1, l2, r2);
	else return min(connect(depth - 1, l1, mid1, l2, mid2), connect(depth - 1, mid1, r1, mid2, r2));
}

ll solve(int depth, int l, int r) {
	if (!depth) return (a[l] ^ a[r - 1]) & 1;
	int mid = binsearch(l, r, depth);
	if (mid == l || mid == r)
		return solve(depth - 1, l, r);
	else return connect(depth - 1, l, mid, mid, r) + solve(depth - 1, l, mid) + solve(depth - 1, mid, r);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%lld", solve(29, 0, n));
}