#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include <queue>

#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

	// srand(time(0));
}

const int N = 2e5 + 228;
const int K = 450;

long long res[N];
int cnt[(int) 1e6 + 228];
int a[N];

long long ans = 0;

struct Qy {
	int l, r, block, who;
	Qy(int y, int u, int i) {
		l = y, r = u, who = i, block = y / K;
	}
};

bool operator<(Qy a, Qy b) {
	if (a.block != b.block)
		return a.block < b.block;
	else 
		return a.r < b.r;
}

void add(long long x) {
	ans -= x * cnt[x] * cnt[x];
	++cnt[x];
	ans += x * cnt[x] * cnt[x];
}

void del(long long x) {
	ans -= x * cnt[x] * cnt[x];
	--cnt[x];
	ans += x * cnt[x] * cnt[x];
}

signed main() {
	setup();
	fill(cnt, cnt + N, 0);

	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<Qy> inquiry;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		inquiry.emplace_back(l - 1, r - 1, i);
	}
	sort(inquiry.begin(), inquiry.end());
	pair<int, int> now = {0, 0};
	add(a[0]);
	for(auto i: inquiry) {
		while(now.first < i.l)
			del(a[now.first++]);
		while(now.first > i.l) 
			add(a[--now.first]);
		while(now.second < i.r)
			add(a[++now.second]);
		while(now.second > i.r) 
			del(a[now.second--]);
		res[i.who] = ans;
	}

	for(int i = 0; i < q; ++i)
		cout << res[i] << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}