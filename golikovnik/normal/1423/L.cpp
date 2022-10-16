// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 1100;
const int C = 32;

std::unordered_map<std::bitset<N>, int> q;
std::bitset<N> a[C];
int ans;

void precalc(int it, int depth, const std::bitset<N>& cur, int cnt) {
	if (it == depth) {
		auto iter = q.find(cur);
		if (iter == q.end()) {
			q[cur] = cnt;
		} else if (iter->second > cnt) {
			q[cur] = cnt;
		}
		return;
	}

	precalc(it + 1, depth, cur, cnt);
	precalc(it + 1, depth, cur ^ a[it], cnt + 1);
}

void solve(int it, int depth, const std::bitset<N>& cur, int cnt) {
	if (it == depth) {
		auto iter = q.find(cur);
		if (iter != q.end()) {
			ans = std::min(ans, iter->second + cnt);
		}
		return;
	}

	solve(it + 1, depth, cur, cnt);
	solve(it + 1, depth, cur ^ a[it], cnt + 1);
}

void run() {
    int n, s, d;
    scanf("%d%d%d", &n, &s, &d);

    for (int i = 0; i < s; ++i) {
    	int sz;
    	scanf("%d", &sz);

    	while (sz--) {
    		int cur;
    		scanf("%d", &cur);
    		a[i][cur - 1] = true;
    	}
    }

    precalc(0, s - s / 3, std::bitset<N>(), 0);

    while (d--) {
    	int sz;
    	scanf("%d", &sz);

    	std::bitset<N> need;
    	while (sz--) {
    		int cur;
    		scanf("%d", &cur);
    		need[cur - 1] = true;
    	}

    	ans = INF;
    	solve(s - s / 3, s, need, 0);

    	if (ans == INF) {
    		printf("-1\n");
    	} else {
    		printf("%d\n", ans);
    	}
    }
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}