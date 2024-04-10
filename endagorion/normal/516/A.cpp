#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int p[4] = {2, 3, 5, 7};

void mulBy(vi &a, int x, int s = 1) {
    forn(i, 4) {
        while (x % p[i] == 0) {
            x /= p[i];
            a[i] += s;
        }
        if (x == 1) break;
    }
}

void mulByFact(vi &a, int x, int s = 1) {
    for (int i = 2; i <= x; ++i) mulBy(a, i, s);
}

map<vi, string> dp;

bool better(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a > b;
}

string count_dp(const vi &a) {
    if (dp.count(a)) return dp[a];
    if (a == vi(4)) {
        return "";
    }
    string &res = dp[a];
    res = "ZZZ";
//    vi b = a;
//    for (int i = 2; i < 10; ++i) {
    forn(j, 4) {
        int i = p[j];
        vi b = a;
        mulByFact(b, i, -1);
        if (*min_element(all(b)) < 0) break;
        string rres = count_dp(b);
        if (rres == "ZZZ") continue;
        rres = (char)('0' + i) + rres;
        if (res == "ZZZ" || better(rres, res)) res = rres;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    string s;
    cin >> s;
    vi a(4);
    forn(i, s.size()) mulByFact(a, s[i] - '0');
    cout << count_dp(a) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}