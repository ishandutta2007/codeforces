#include <bits/stdc++.h>
#define N 200050
using namespace std;
int n, m, o[N];
inline int rd() {int r;scanf("%d",&r);return r;}
struct Node{
	int x, w, id;
}a[N];



bool cmp(Node p1, Node p2) {
	return p1.w < p2.w;
}

bool cmp2(int p1, int p2) {
	return a[p1].x < a[p2].x;
}

int main() {
	int T; scanf("%d",&T);
	while (T--) {
		n = rd(), m = rd();
		for (int i=1;i<=m;i++) a[i].x = rd(), a[i].w = rd(), a[i].id = i;
		sort(a+1, a+m+1, cmp);
		int ans = 0;
		for (int i=1;i<=2*n;i++) {
			ans += a[i].w;
			o[i] = i;
		}
		sort(o+1, o+2*n+1, cmp2);
		printf("%d\n", ans);
		for (int i=1;i<=n;i++)
			printf("%d %d\n", a[o[i]].id, a[o[2*n-i+1]].id);
		
		
	}
	return 0;
}