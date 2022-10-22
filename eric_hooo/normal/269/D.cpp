#include <bits/stdc++.h>
using namespace std;

struct Node{
	int l, r, h;
	Node(){}
	Node(int _l, int _r, int _h){l = _l, r = _r, h = _h;}
	bool operator < (const Node &A) const{
		return h > A.h; 
	}
}a[100010];

vector <int> all;
int tot;

struct Segment{
	struct Node{
		int id, lazy;
	}T[800010];
	void pushup(int now){
		T[now].id = max(T[now << 1].id, T[now << 1 | 1].id);
	}
	void pushdown(int now){
		if (T[now].lazy == -1) return ;
		int v = T[now].lazy; T[now].lazy = -1;
		T[now << 1].id = T[now << 1].lazy = v;
		T[now << 1 | 1].id = T[now << 1 | 1].lazy = v;
	}
	void Build(int now, int l, int r){
		T[now].lazy = -1, T[now].id = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int L, int R, int x){
		if (l == L && r == R){
			T[now].id = T[now].lazy = x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R){
		if (l == L && r == R) return T[now].id;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

int dp[100010];

int get_id(int x){
	return lower_bound(all.begin(), all.end(), x) - all.begin();
}

void get_dp(int l, int r, int id, int pdl, int pdr){
	if (l > r) return ;
	int pos = seg.Query(1, 0, tot - 1, l, r);
	int ll = a[pos].l, rr = a[pos].r;
	if ((!pdl || (pdl && ll >= l)) && (!pdr || (pdr && rr <= r))){
//		cout << "    " << pos << "->" << id << endl;
		dp[id] = max(dp[id], min(dp[pos], min(all[r + 1], all[rr + 1]) - max(all[l], all[ll])));
	}
	get_dp(l, ll - 1, id, pdl, 1);
	get_dp(rr + 1, r, id, 1, pdr);
}

int main(){
	int n, t; scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++){
		int l, r, h;
		scanf("%d%d%d", &h, &l, &r);
		a[i] = Node(l, r, h);
		all.push_back(l), all.push_back(r);
	}
	a[n++] = Node(-1e9, 1e9, t), a[n++] = Node(-1e9, 1e9, 0);
	all.push_back(-1e9), all.push_back(1e9);
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	tot = all.size();
	sort(a, a + n);
	seg.Build(1, 0, tot - 1);
	dp[0] = 2100000000;
	a[0].l = get_id(a[0].l), a[0].r = get_id(a[0].r) - 1;
	for (int i = 1; i < n; i++){
		a[i].l = get_id(a[i].l), a[i].r = get_id(a[i].r) - 1;
		get_dp(a[i].l, a[i].r, i, 0, 0);
//		cout << "Update:" << a[i].l << " " << a[i].r << " " << i << endl; 
		seg.Update(1, 0, tot - 1, a[i].l, a[i].r, i);
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}