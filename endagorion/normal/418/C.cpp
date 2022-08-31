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

int a[101], b[101];

void fill(int *a, int N) {
    if (N == 1) {
        a[0] = 1;
        return;
    }
    if (N == 2) {
        a[0] = 3;
        a[1] = 4;
        return;
    }
    forn(i, N - 1) {
        a[i] = 1;
    }
    if (N % 2 == 0) {
        a[N - 1] = (N - 1) / 2;
        return;
    }
    a[N - 2] = 2;
    a[N - 1] = (N + 2) / 2;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int N, M;
    cin >> N >> M;
    fill(a, N);
    fill(b, M);
    forn(i, N) {
        forn(j, M) {
            cout << a[i] * b[j] << ' ';
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}