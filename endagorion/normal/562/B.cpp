#pragma comment(linker, "/STACK:512000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cmath>
#include <queue>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef long double ld;

const int MAXN = 1100000;
int a[MAXN], dp[MAXN];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    forn(i, N) {
        int x;
        cin >> x;
        a[x] = 1;
        dp[x] = 1;
    }

    int ans = 0;
    for1(i, MAXN - 1) {
        if (!a[i]) continue;
        ans = max(ans, dp[i]);
        for (int j = 2 * i; j < MAXN; j += i) {
            if (!a[j]) continue;
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}