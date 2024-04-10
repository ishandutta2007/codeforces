// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
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

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 200100;

int a[N], t[N];
ll dp[N];

void run() {
    int n, v;
    scanf("%d%d", &n, &v);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    std::vector<std::pair<ll, ll>> shit;
    for (int i = 0; i < n; ++i) {
        if (llabs(a[i]) > 1ll * v * t[i]) {
            continue;
        }
        shit.push_back(std::make_pair(1ll * v * t[i] - a[i], 1ll * v * t[i] + a[i]));
    }

    std::sort(shit.begin(), shit.end());
    dp[0] = -LINF;
    for (int i = 1; i < N; ++i) {
        dp[i] = LINF;
    }

    for (auto[x, y] : shit) {
        auto j = std::upper_bound(dp, dp + N, y) - dp;
        smin(dp[j], y);
    }

    for (int i = N - 1; i >= 0; --i) {
        if (dp[i] != LINF) {
            printf("%d\n", i);
            return;
        }
    }

    throw;
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