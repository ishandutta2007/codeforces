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
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

string s;
int N;

const int MAXN = 5002;
int lcs[MAXN][MAXN];
//i64 parts[MAXN][MAXN];
int ways[MAXN][MAXN], sways[MAXN][MAXN];
int mind[MAXN][MAXN], smind[MAXN][MAXN];

bool subleq(int i, int j, int d) {
    if (j == 0) return true;
	if (s[i] == '0' || s[j] == '0') return false;
    if (i < 0) return false;
    int l = lcs[i][j];
    return l >= d || s[i + l] < s[j + l];
}

string sum(const string &s, const string &t) {
    string u(max(s.size(), t.size()) + 1, '0');
    int d = 0;
    forn(i, u.size()) {
        if (i < s.size()) d += s[i] - '0';
        if (i < t.size()) d += t[i] - '0';
        u[i] = (char)('0' + d % 2);
        d /= 2;
    }
    while (u.back() == '0') u.resize(u.size() - 1);
    return u;
}

string bin(int x) {
    string s;
    while (x) {
        s += (char)('0' + x % 2);
        x /= 2;

    }
    return s;
}

bool cmp(const string &s, const string &t) {
    if (s.size() != t.size()) return s.size() < t.size();
    ford(i, s.size()) if (s[i] != t[i]) return s[i] < t[i];
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> s;
    N = s.size();
    forn(d, N + 1) {
        lcs[N - d][N] = 0;
        for (int i = N - d - 1; i >= 0; --i) {
            if (s[i] == s[i + d]) lcs[i][i + d] = lcs[i + 1][i + d + 1] + 1;
            else lcs[i][i + d] = 0;
        }
    }
/*    for (int l = 1; l <= N; ++l) {
        for (int i = N - l; i >= 0; --i) {
            if (s[i] == '0') {
                parts[i][l] = 0;
            } else {
                int d = lcs[i][i + l];
                if (d >= l || s[i + d] > s[i + l + d]) parts[i][l] = parts[i + l][l] + 1;
                else parts[i][l] = 1;
            }
        }
    }*/
    forn(i, N + 1) ways[0][i] = 1;
    const i64 P = 1000000000 + 7;
    forn(i, N + 1) forn(j, N + 1) mind[i][j] = smind[i][j] = 1e9;
    forn(i, N + 1) smind[0][i] = 0;
    mind[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int l = 1; l <= N; ++l) {
            ways[i][l] = ways[i][l - 1];
//            mind[i][l] = mind[i][l - 1];
            if (l <= i) {
                if (subleq(i - 2 * l, i - l, l)) {
                    //ways[i][l] += sways[i - l][l] + ways[i - l]
                    sways[i][l] = sways[i - l][l] + ways[i - l][l - 1];
                    mind[i][l] = smind[i - l][l] + 1;
                } else if (s[i - l] == '1') {
                    sways[i][l] = ways[i - l][l - 1];
                    mind[i][l] = smind[i - l][l - 1] + 1;
                }
                sways[i][l] %= P;
                ways[i][l] += sways[i][l];
                ways[i][l] %= P;
            }
			smind[i][l] = min(smind[i][l - 1], mind[i][l]);
        }
    }
    string best(N + 1, '1');    
    for (int l = 1; l <= N; ++l) {
        string t(s.end() - l, s.end());
        reverse(all(t));
        if (mind[N][l] > 1e8) continue;
        string w = bin(mind[N][l]);
        w = sum(t, w);
        if (cmp(w, best)) best = w;
    }
    i64 minl = 0;
    ford(i, best.size()) {
        minl = 2 * minl + (best[i] - '0');
		minl %= P;
    }

    /*i64 ans = 0;
    forn(i, N + 1) ans += ways[N][i];
    ans %= P;*/
    cout << ways[N][N] << '\n';
    cout << minl << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}