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

const int M = 1000000;
int minD[M + 1];
int phi[M + 1];
i64 c[M + 1];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    forn(i, M + 1) minD[i] = i;
    vector<int> primes;
    phi[1] = 1;
    for (int i = 2; i <= M; ++i) {
        if (minD[i] == i) primes.pb(i);
        if (minD[i] == minD[i / minD[i]]) phi[i] = phi[i / minD[i]] * minD[i];
        else phi[i] = phi[i / minD[i]] * (minD[i] - 1);
        for (size_t j = 0; j < primes.size() && primes[j] <= minD[i] && i * primes[j] <= M; ++j) {
            minD[i * primes[j]] = primes[j];
        }
    }
//    forn(i, M + 1) cout << phi[i] << '\n';
    int N;
    cin >> N;
    vector< pair<i64, i64> > q;
    forn(i, N) {
        i64 p, n;
        cin >> p >> n;
        c[p] = n;
    }
    i64 K;
    cin >> K;
    forn(i, min(K, 20LL)) {
        for (int j = 2; j <= M; ++j) {
            if (minD[j] == j && c[j]) {
                ++c[phi[j]];
                --c[j];
            }
        }
        for (int j = M; j >= 2; --j) {
            if (minD[j] != j) {
                c[minD[j]] += c[j];
                c[j / minD[j]] += c[j];
                c[j] = 0;
            }
        }
        c[1] = 0;
    }
    K = max(0LL, K - 20);
    for (int i = M; i >= 2; --i) {
        if (i != minD[i]) continue;
        i64 q = min(c[i], K);
        c[i] -= q;
        for (int j = i - 1; j > 1; j /= minD[j]) {
            c[minD[j]] += q;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= M; ++i) {
        if (minD[i] == i && c[i]) {
            ++cnt;                
        }
    }
    cout << cnt << '\n';
    for (int i = 2; i <= M; ++i) {
        if (minD[i] == i && c[i]) {
            cout << i << ' ' << c[i] << '\n';
        }
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}