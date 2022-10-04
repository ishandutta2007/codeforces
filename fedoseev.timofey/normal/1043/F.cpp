#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

vector <int> d[N];
int p[N];
int cnt[N];
int cur[N];
int mem[N];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 2; i < N; ++i) p[i] = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            d[i].push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                p[j] = 0;
                d[j].push_back(i);
            }
        }
    }
    int n;
    cin >> n;
    vector <int> a(n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        ++cnt[x];
        g = gcd(g, x);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 2 * i; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }
    if (g != 1) {
        cout << "-1\n";
        return 0;
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int lim = (1 << d[a[i]].size());
        int sz = d[a[i]].size();
        for (int mask = 0; mask < lim; ++mask) {
            int x = 1;
            for (int j = 0; j < sz; ++j) {
                if (mask & (1 << j)) {
                    x *= d[a[i]][j];
                }
            }
            cur[mask] = cnt[x];
        }
        for (int mask = 0; mask < lim; ++mask) mem[mask] = 0;
        for (int mask = 0; mask < lim; ++mask) {
            for (int nmask = 0; nmask < lim; ++nmask) {
                if ((mask & nmask) == mask) {
                    int c = mask ^ nmask;
                    if (__builtin_popcount(c) & 1) {
                        mem[mask] -= cur[nmask];
                    }
                    else {
                        mem[mask] += cur[nmask];
                    }
                }
            }
        }
        vector <int> dp(lim, 1e9);
        dp[lim - 1] = 1;
        for (int i = 0; i < lim; ++i) {
            if (!mem[i]) continue;
            for (int j = 0; j < lim; ++j) {
                dp[i & j] = min(dp[i & j], dp[j] + 1);
            }
        }
        ans = min(ans, dp[0]);
    }
    cout << ans << '\n';
}