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

bool isPrime(int N) {
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

bool isRoot(int x, int N) {
    for (int i = 1, y = x; i < N - 1; ++i, y = (1LL * y * x) % N) {
        if (y == 1) return false;
    }
    return true;
}

int degs[110001];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    if (N == 1) {
        cout << "YES\n1\n";
        return 0;
    }
    if (N == 2) {
        cout << "YES\n1\n2\n";
        return 0;
    }
    if (N == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    if (!isPrime(N)) {
        cout << "NO\n";
        return 0;
    }
    int g = 2;
    while (!isRoot(g, N)) ++g;
    degs[0] = 1;
    forn(i, N) {
        degs[i + 1] = (1LL * degs[i] * g) % N;
    }

    cout << "YES\n";
    forn(i, N - 1) {
        if (i % 2) cout << degs[N - 1 - i] << '\n';
        else cout << degs[i] << '\n';
    }
    cout << N << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}