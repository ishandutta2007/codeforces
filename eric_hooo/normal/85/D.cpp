#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <char, int> pci;

vector <int> all;
vector <pci> q;

int get_id(int x){
	return lower_bound(all.begin(), all.end(), x) - all.begin();
}

struct Segment_tree{
	struct Node{
		int size;
		long long sum[5];
	}T[400010];
	void pushup(int now){
		for (int i = 0; i < 5; i++){
			T[now].sum[i] = T[now << 1].sum[i];
		}
		T[now].size = T[now << 1].size;
		for (int i = 0; i < 5; i++){
			T[now].sum[(i + T[now].size)%5] += T[now << 1 | 1].sum[i];
		}
		T[now].size += T[now << 1 | 1].size;
	}
	void Build(int now, int l, int r){
		if (l == r){
			T[now].size = 0;
			memset(T[now].sum, 0, sizeof(T[now].sum));
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int pos, int x){
		if (l == r){
			T[now].size = x;
			memset(T[now].sum, 0, sizeof(T[now].sum));
			T[now].sum[1] = x*all[l];
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		pushup(now);
	}
	long long sum(){return T[1].sum[3];}
}seg;

int main(){
	int n; scanf("%d", &n);
	while (n--){
		char op[5];
		scanf("%s", op);
		int x = -1;
		if (op[0] != 's') scanf("%d", &x), all.push_back(x);
		q.push_back(mp(op[0], x));
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	int m = all.size();
	if (m) seg.Build(1, 0, m - 1);
	for (int i = 0; i < q.size(); i++){
		char c = q[i].fi;
		int x = get_id(q[i].se);
		if (c == 's') printf("%I64d\n", seg.sum());
		else if (c == 'a') seg.Update(1, 0, m - 1, x, 1);
		else seg.Update(1, 0, m - 1, x, 0);
	}
	return 0;
}