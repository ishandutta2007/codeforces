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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
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

const int MAXN = 210000;
const i64 P = 1000000000 + 7;
int p[MAXN];
int ways[MAXN], sways[MAXN], ssways[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s, t;
    cin >> s >> t;
    int N = s.size(), M = t.size();
    string w = t + '#' + s;
    for1(i, w.size() - 1) {
        p[i] = p[i - 1];
        while (p[i] && w[i] != w[p[i]]) p[i] = p[p[i] - 1];
        if (w[i] == w[p[i]]) ++p[i];
    }
    sways[0] = ssways[0] = 1;
    int pos = -1;
    forn(i, N) {
        if (p[M + 1 + i] == M) pos = i - M + 1;
        if (pos >= 0) ways[i] = ssways[pos];
        sways[i + 1] = (sways[i] + ways[i]) % P;
        ssways[i + 1] = (ssways[i] + sways[i + 1]) % P;
    }
    cout << (sways[N] + P - 1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}