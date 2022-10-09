#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include <queue>

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

struct query {
	int l, r, i;
	query() {

	}
	query(int a, int b, int c) {
		l = a, r = b, i = c;
	}
};

const int K = 317;
const int N = 1e5 + 228;

int cnt[N];
int res[N];

int ans = 0;

void add(int a) {
	if (cnt[a] == a) 
		--ans;
	++cnt[a];
	if (cnt[a] == a)
		++ans;
}

void del(int a) {
	if (cnt[a] == a)
		--ans;
	--cnt[a];
	if (cnt[a] == a)
		++ans;
}

signed main() {
	setup();
	fill(cnt, cnt + N, 0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &i: a) {
		cin >> i;
		i = min(N, i);
	}
	vector<query> q(m);
	for(int i = 0; i < m; ++i) {
		cin >> q[i].l >> q[i].r;
		q[i].i = i;
		--q[i].l, --q[i].r;
	}
	sort(q.begin(), q.end(), [](const query &a, const query &b) {
		return make_pair(a.l / K, a.r) < make_pair(b.l / K, b.r);
	});

	pair<int, int> now = {0, 0};
	add(a[0]);
	for(auto cur: q) {
		while(now.first > cur.l) 
			add(a[--now.first]);
		while(now.first < cur.l)
			del(a[now.first++]);
		while(now.second < cur.r)
			add(a[++now.second]);
		while(now.second > cur.r)
			del(a[now.second--]);
		res[cur.i] = ans;
	}
	for(int i = 0; i < m; ++i)
		cout << res[i] << '\n';
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}