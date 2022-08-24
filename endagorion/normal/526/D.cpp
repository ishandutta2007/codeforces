#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

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

const int MAXN = 1000001;
int d[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, K;
    string s;
    cin >> N >> K >> s;
    vi z(N + 1);
/*    if (K == 1) {
        cout << string(N, '1') << '\n';
        return 0;
    }*/
    int L = 0, R = 0;
    for (int i = 1; i < N; ++i) {
        if (R < i) L = R = i;
        z[i] = min(z[i - L], R - i);
        while (i + z[i] < N && s[z[i]] == s[i + z[i]]) {
            ++z[i];
            L = i;
            R = i + z[i];
        }
//        cerr << i << ' ' << z[i] << '\n';
    }
    for (int ab = 1; ab * K <= N; ++ab) {
        if (z[ab] < (K - 1) * ab) continue;
        int l = K * ab, r = min(N, min((K + 1) * ab, z[ab] + ab));
        ++d[l - 1]; --d[r];
    }    
    string ans;
    int c = 0;
    forn(i, N) {
        c += d[i];
        ans += (c > 0 ? '1' : '0');
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}