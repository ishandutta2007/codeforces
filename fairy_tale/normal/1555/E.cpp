#include <bits/stdc++.h>
const int MAXN = 3'000'00 + 10;
const int MAXM = 1'000'000 + 10;
using namespace std;
int n, m;
struct seg {
	int l, r, w;
} segs[MAXN];
struct Node {
	int cnt;
	int flag;
} segTree[MAXM * 4];
int cmp(seg a, seg b) {
	return a.w < b.w;
}
void addNode(int n, int l, int r, int pos, int num)
{
	if (segs[n].l <= l && r <= segs[n].r) {
		segTree[pos].cnt += num;
		segTree[pos].flag += num;
		return;
	}
	segTree[pos * 2].flag += segTree[pos].flag;
	segTree[pos * 2].cnt += segTree[pos].flag;
	segTree[pos * 2 + 1].flag += segTree[pos].flag;
	segTree[pos * 2 + 1].cnt += segTree[pos].flag;
	segTree[pos].flag = 0;
	int mid = (l + r) / 2;
	if (mid >= segs[n].l) addNode(n, l, mid, pos * 2, num);
	if (mid < segs[n].r) addNode(n, mid + 1, r, pos * 2 + 1, num);
	segTree[pos].cnt = min(segTree[pos * 2].cnt, segTree[pos * 2 + 1].cnt);
}
int main()
{
	scanf("%d%d", &n, &m);
	m--;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &segs[i].l, &segs[i].r, &segs[i].w);
		segs[i].r--;
		if (segs[i].r == m && segs[i].l == 1) {
			printf("0\n");
			return 0;
		}
	}
	sort(segs, segs + n, cmp);
	addNode(0, 1, m, 1, 1);
	int ans = 1'000'000 + 1;
	for (int l = 0, r = 0; l < n; l++){
		while (segTree[1].cnt == 0) {
			r++;
			if (r == n) break;
			addNode(r, 1, m, 1, 1);
		}
		if (r == n) break;
		ans = min(ans, segs[r].w - segs[l].w);
		addNode(l, 1, m, 1, -1);
	}
	printf("%d", ans);
}