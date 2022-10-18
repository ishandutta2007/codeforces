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
const int N = 5100;

char s[N];

bool check(int n, int badX, int badY) {
    int x = 0, y = 0;

    for (int i = 0; i < n; ++i) {
        int newX = x, newY = y;

        if (s[i] == 'U') {
            ++newY;
        } else if (s[i] == 'D') {
            --newY;
        } else if (s[i] == 'L') {
            --newX;
        } else {
            ++newX;
        }

        if (newX == badX && newY == badY) {
            continue;
        }

        x = newX;
        y = newY;
    }

    if (x == 0 && y == 0) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    scanf("\n%s", s);
    int n = strlen(s);

    std::vector<std::pair<int, int>> a;
    int x = 0, y = 0;
    a.push_back(std::make_pair(0, 0));

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            ++y;
        } else if (s[i] == 'D') {
            --y;
        } else if (s[i] == 'L') {
            --x;
        } else {
            ++x;
        }

        a.push_back(std::make_pair(x, y));
    }

    for (auto i : a) {
        if (i.first == 0 && i.second == 0) {
            continue;
        }
        if (check(n, i.first, i.second)) {
            printf("%d %d\n", i.first, i.second);
            return;
        }
    }

    printf("0 0\n");
}

void run() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
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