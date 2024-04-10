// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	srand(time(0));
}

struct node {
	int x, y, size;
	node *L, *R;
	node(int who) {
		x = who, y = rand() * (RAND_MAX + 1);
		L = 0, R = 0;
		size = 1;
	}
};

int size(node* a) {
	if (a == 0)
		return 0;
	return a->size;
}

void update(node* a) {
	a->size = size(a->L) + size(a->R) + 1;
}

node* merge(node* a, node* b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a->y > b->y) {
		a->R = merge(a->R, b);
		update(a);
		return a;
	}
	else {
		b->L = merge(a, b->L);
		update(b);
		return b;
	}
}

pair<node*, node*> split(node* a, int k) {
	if (a == 0)
		return {0, 0};
	if (a->x > k) {
		auto z = split(a->L, k);
		a->L = z.second;
		update(a);
		return {z.first, a};
	}
	else {
		auto z = split(a->R, k);
		a->R = z.first;
		update(a);
		return {a, z.second};
	}
}

void print(node* a) {
	if (a == 0)
		return;
	print(a->L);
	cout << a->x << ' ';
	print(a->R);
}

// 11:29

signed main() {
	setup();
	
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	node* p = new node(0);
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		auto z = split(p, sum - t);
		ans += size(z.second);
		p = merge(z.first, z.second);
		z = split(p, sum);
		p = merge(z.first, new node(sum));
		p = merge(p, z.second);
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}