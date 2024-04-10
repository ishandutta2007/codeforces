#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e15 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
const int MAXV = 1e9 + 7;

int dp[MAXN];

struct Node{
	Node *l, *r;
	int val;
};

Node *init(){
	Node *res = new Node();
	res->l = NULL;
	res->r = NULL;
	res->val = -MOD;
	return res;
}

Node* push(Node *t){
	if (!t->l) t->l = init();
	if (!t->r) t->r = init();
	return t;
}

pair <Node*, int> get(Node *t, int tl, int tr, int l, int r){
	if (tl > r || l > tr) return{ t, -MOD };
	if (tl >= l && tr <= r) return{ t, t->val };
	int m = (tl + tr) / 2;
	t = push(t);
	auto res1 = get(t->l, tl, m, l, r);
	auto res2 = get(t->r, m + 1, tr, l, r);
	t->l = res1.first;
	t->r = res2.first;
	return{ t, max(res1.second, res2.second)};
}

Node *upd(Node *t, int tl, int tr, int i, int val){
	if (tl == tr){
		t->val = max(t->val, val);
		return t;
	}

	int m = (tl + tr) / 2;
	t = push(t);
	if (i <= m){
		t->l = upd(t->l, tl, m, i, val);
	}
	else{
		t->r = upd(t->r, m + 1, tr, i, val);
	}

	t->val = max(t->l->val, t->r->val);
	return t;
}

struct disk{
	int h, mn, mx;
};

bool comp(disk a, disk b){
	return (a.mx > b.mx) || (a.mx == b.mx && a.mn > b.mn);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	Node *root = init();
	root = upd(root, 0, MAXV, 0, 0);
	int n;
	cin >> n;
	vector <disk> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].mn >> a[i].mx >> a[i].h;
	}

	sort(a.begin(), a.end(), comp);

	dp[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		auto tmp = get(root, 0, MAXV, 0, a[i - 1].mx - 1);
		root = tmp.first;
		dp[i] = tmp.second + a[i - 1].h;
		ans = max(ans, dp[i]);
		root = upd(root, 0, MAXV, a[i - 1].mn, dp[i]);
	}

	cout << ans << '\n';
	return 0;
}