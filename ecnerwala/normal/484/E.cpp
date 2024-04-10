#include<bits/stdc++.h>
using namespace std;

struct range {
	int len;
	int val, pref, suff;
};

range operator + (range l, range r) {
	range res;
	res.len = l.len + r.len;
	res.val = max(max(l.val, r.val), l.suff + r.pref);
	res.pref = (l.pref == l.len) ? (l.len + r.pref) : l.pref;
	res.suff = (r.suff == r.len) ? (r.len + l.suff) : r.suff;
	return res;
}

range ZERO, ONE;

const int MAXN = 1e5 + 200;
const int MAXV = MAXN * 100;

int N;
int H[MAXN];
pair<int, int> heights[MAXN];


int V = 0;
range val[MAXV];
int ch[MAXV][2];

int trees[MAXN];

int M;

// inclusive, exclusive
int init(int l, int r) {
	int i = V++;
	assert(r > l);
	if(r - l == 1) {
		ch[i][0] = ch[i][1] = -1;
		val[i] = ZERO;
		assert(val[i].len == ZERO.len);
		assert(val[i].val == ZERO.val);
		assert(r - l == val[i].len);
	} else {
		int m = (l + r) / 2;
		ch[i][0] = init(l, m);
		ch[i][1] = init(m, r);
		assert(val[ch[i][0]].len == m - l);
		assert(val[ch[i][1]].len == r - m);
		val[i] = val[ch[i][0]] + val[ch[i][1]];
		assert(r - l == val[i].len);
	}
	return i;
}

int update(int i, int l, int r, int v) {
	assert(l <= v && v < r);
	int j = V++;
	if(r - l == 1) {
		assert(val[i].len == ZERO.len);
		assert(val[i].val == ZERO.val);
		ch[j][0] = ch[j][1] = -1;
		val[j] = ONE;
	} else {
		int m = (l + r) / 2;
		ch[j][0] = ch[i][0], ch[j][1] = ch[i][1];
		if(v < m) ch[j][0] = update(ch[i][0], l, m, v);
		else ch[j][1] = update(ch[i][1], m, r, v);
		val[j] = val[ch[j][0]] + val[ch[j][1]];
	}
	return j;
}

range query(int i, int l, int r, int a, int b) {
	assert(l <= a && a < b && b <= r);
	assert(r - l == val[i].len);
	if(b - a == r - l) {
		return val[i];
	}
	assert(r - l > 1);
	int m = (l + r) / 2;
	if(b <= m) {
		return query(ch[i][0], l, m, a, b);
	} else if(m <= a) {
		return query(ch[i][1], m, r, a, b);
	} else {
		assert(a < m);
		assert(m < b);
		return query(ch[i][0], l, m, a, m) + query(ch[i][1], m, r, m, b);
	}
} 

int main() {
	ZERO.len = ONE.len = 1;
	ZERO.val = ZERO.pref = ZERO.suff = 0;
	ONE.val = ONE.pref = ONE.suff = 1;

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> H[i];
		heights[i] = make_pair(H[i], i);
	}

	sort(heights, heights + N);

	trees[N] = init(0, N);

	for(int i = N - 1; i >= 0; i--) {
		trees[i] = update(trees[i + 1], 0, N, heights[i].second);
	}

	cin >> M;
	for(int i = 0; i < M; i++) {
		int w, l, r; cin >> l >> r >> w;
		l--;
		int mi = 0, ma = N;
		while(ma - mi > 1) {
			int md = (mi + ma) / 2;
			if(query(trees[md], 0, N, l, r).val >= w) {
				mi = md;
			} else {
				ma = md;
			}
		}
		cout << heights[mi].first << '\n';
	}

	return 0;
}