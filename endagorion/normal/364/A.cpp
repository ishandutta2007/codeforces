#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

i64 c[50000];

i64 get(int x) {
    if (x >= 50000) {
        return 0;
    }
    return c[x];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int A;
    string s;
    cin >> A >> s;

    forn(i, s.size()) {
        int t = 0;
        for (int j = i; j < s.size(); ++j) {
            t += s[j] - '0';
            ++c[t];
        }
    }

    if (A == 0) {
        cout << 2 * get(0) * s.size() * (s.size() + 1) / 2 - get(0) * get(0) << '\n';
        return 0;
    }

    i64 ans = 0;
    for (int x = 1; x * x <= A; ++x) {
        if (A % x == 0) {
            ans += get(x) * get(A / x);
            if (x * x < A) {
                ans += get(x) * get(A / x);
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}