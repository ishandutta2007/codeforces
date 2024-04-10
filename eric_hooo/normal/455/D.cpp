#include <bits/stdc++.h>
using namespace std;

int in[100010];
int cnt[320][100010];
deque <int> block[320];
int n, m;

void print(string s){
	for (int i = 0; i <= (n - 1) / m; i++){
		printf("%sblock %d:", s.c_str(), i);
		for (int j = 0; j < block[i].size(); j++){
			printf(" %d", block[i][j]);
		}
		printf("\n");
	}
}

void change(int l, int r){
//	cout << "  " << l << " " << r << endl;
	int lb = in[l], rb = in[r];
//	cout << "  " << lb << " " << rb << endl;
	if (lb == rb){
		int now = lb * m;
		int tmp = block[lb][r - now];
		for (int i = r - now; i >= l - now + 1; i--){
			block[lb][i] = block[lb][i - 1];
		}
		block[lb][l - now] = tmp;
		return ;
	}
//	cout << "   POS" << endl;
	for (int i = lb; i < rb; i++){
		block[i + 1].push_front(block[i].back());
		cnt[i][block[i].back()]--, cnt[i + 1][block[i].back()]++;
		block[i].pop_back();
	}
//	print("    ");
//	cout << "   POS" << endl;
	int t = lb * m, now = rb * m - 1;
//	cout << "  " << l - t << " " << r - now << endl;
//	cout << "  " << block[lb].size() << " " << block[rb].size() << endl;
	deque <int> :: iterator p = block[lb].begin();
	for (int i = 0; i < l - t; i++){
		p++;
	}
	block[lb].insert(p, block[rb][r - now]);
//	cout << "   POS" << endl;
	cnt[lb][block[rb][r - now]]++, cnt[rb][block[rb][r - now]]--;
	p = block[rb].begin();
	for (int i = 0; i < r - now; i++){
		p++;
	}
	block[rb].erase(p);
}

int get_sum(int l, int r, int k){
//	cout << "  " << l << " " << r << " " << k << endl;
	int lb = in[l], rb = in[r];
	if (lb == rb){
		int now = lb * m, res = 0;
		for (int i = l - now; i <= r - now; i++){
			if (block[lb][i] == k) res++;
		}
		return res;
	}
	int res = 0;
	for (int i = lb + 1; i < rb; i++){
		res += cnt[i][k];
	}
	for (int i = l - lb * m; i < block[lb].size(); i++){
		if (block[lb][i] == k) res++;
	}
	for (int i = 0; i <= r - rb * m; i++){
		if (block[rb][i] == k) res++;
	}
	return res;
}

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	scanf("%d", &n), m = sqrt(n);
//	cout << "  " << m << endl;
//	cout << "  " << (n - 1) / m << endl;
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		block[i / m].push_back(x);
		cnt[i / m][x]++, in[i] = i / m;
	}
	int q, lastans = 0;
//	print("    ");
	scanf("%d", &q);
	while (q--){
		int op, l, r, k;
		scanf("%d%d%d", &op, &l, &r);
		l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1;
		if (l > r) swap(l, r);
		l--, r--;
//		cout << "  " << l << " " << r << endl;
//		cout << q << " " << op << " " << l << " " << r << " " << k << endl;
		if (op == 1) change(l, r);
		else {
			scanf("%d", &k);
			k = (k + lastans - 1) % n + 1;
			lastans = get_sum(l, r, k), printf("%d\n", lastans);
		}
//		print("        ");
	}
	return 0;
}