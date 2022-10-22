#include <bits/stdc++.h>
using namespace std;

struct Node{
	int x, h, flag;
	Node(){}
	Node(int _x, int _h, int f){x = _x, h = _h, flag = f;}
	bool operator < (const Node &A) const{
		return x < A.x;
	}
}a[200010];

int all[100010], tot;
int T[100010];

void add(int x, int v){
	while (x < tot) T[x] += v, x += x & -x;
}

int sum(int x){
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; scanf("%d", &n);
	all[tot++] = 0;
	for (int i = 0; i < n; i++){
		int h, l, r;
		scanf("%d%d%d", &h, &l, &r);
		a[2 * i] = Node(l, h, 1), a[2 * i + 1] = Node(r, h, -1);
		all[tot++] = h;
	}
	all[tot++] = -1;
	sort(all, all + tot), tot = unique(all, all + tot) - all;
	sort(a, a + 2 * n);
	int last = 0;
	vector <int> xx, yy;
	for (int i = 0; i < 2 * n; i++){
		a[i].h = lower_bound(all, all + tot, a[i].h) - all;
		add(1, a[i].flag), add(a[i].h + 1, -a[i].flag);
		i++;
		while (a[i].x == a[i - 1].x){
			a[i].h = lower_bound(all, all + tot, a[i].h) - all;
			add(1, a[i].flag), add(a[i].h + 1, -a[i].flag);
			i++;
		}
		i--;
		int l = 1, r = tot - 1;
		while (l < r){
			int mid = l + r + 1 >> 1;
			if (sum(mid) == 0) r = mid - 1;
			else l = mid;
		}
		if (last == all[l]) continue;
		xx.push_back(a[i].x), xx.push_back(a[i].x);
		yy.push_back(last), yy.push_back(all[l]);
		last = all[l];
	}
	printf("%d\n", xx.size());
	for (int i = 0; i < xx.size(); i++){
		printf("%d %d\n", xx[i], yy[i]);
	}
	return 0;
}