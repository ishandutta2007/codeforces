#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int mod = 1000000007;
int h, w, n;
vector<int> ht[100100];
vector<int> vn[100100];
struct bar {
	int h, l, r, s;
	bool operator<(const bar&r)const {
		return h > r.h;
	}
};
bar b[100100];
int it[1 << 18];
void update(int x) {
	x /= 2;
	while (x != 0) {
		int l = it[x * 2];
		int r = it[x * 2 + 1];
		if (ht[r].size() == 0 || (ht[l].size() != 0 && ht[l][ht[l].size() - 1] < ht[r][ht[r].size() - 1])) {
			it[x] = l;
		}
		else {
			it[x] = r;
		}
		x /= 2;
	}
}
void push(int idx, int hl, int val) {
	ht[idx].push_back(hl);
	vn[idx].push_back(val);
	int x = idx + (1 << 17);
	it[x] = idx;
	update(x);
}
int itpop(int mh, int loc) {
	int p = it[loc];
	if (ht[p].size() == 0 || ht[p][ht[p].size() - 1] > mh)return 0;
	int res = vn[p][ht[p].size() - 1];
	ht[p].pop_back();
	vn[p].pop_back();
	update(p + (1 << 17));
	return (res + itpop(mh, loc)) % mod;
}
int calc(int mh, int start, int end) {
	int res = 0;
	start += 1 << 17;
	end += 1 << 17;
	while (start <= end) {
		if (start % 2 == 1) {
			res += itpop(mh, start);
			res %= mod;
			start++;
		}
		if (end % 2 == 0) {
			res += itpop(mh, end);
			res %= mod;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
int main() {
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &b[i].h, &b[i].l, &b[i].r, &b[i].s);
		b[i].l--;
		b[i].r--;
	}
	sort(b, b + n);
	for (int i = 0; i < w; i++) {
		push(i, h + 1, 1);
	}
	for (int i = 0; i < n; i++) {
		int res = calc(b[i].h + b[i].s, b[i].l, b[i].r);
		if (b[i].l > 0)push(b[i].l - 1, b[i].h, res);
		else push(b[i].r + 1, b[i].h, res);
		if (b[i].r == w - 1)push(b[i].l - 1, b[i].h, res);
		else push(b[i].r + 1, b[i].h, res);
	}
	printf("%d", calc(2147483646, 0, w - 1));
	return 0;
}