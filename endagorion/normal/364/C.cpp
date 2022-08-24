#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
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
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

bool allUnique(vector<int> a) {
    return unique(all(a)) - a.begin() == a.size();
}

bool isPrime(int k) {
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int K, L;
    cin >> K >> L;
    vector<int> a(1, 1);
    set<int> s;
    s.insert(1);
    for (int j = 2; a.size() < K; ++j) {
        if (!isPrime(j)) {
            continue;
        }
        int q = a.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] * j <= 2 * K * K) {
                a.pb(a[i] * j);
            }
        }
//        sort(rall(a));
    }
//    assert(a.back() <= 2 * K * K);
//    random_shuffle(all(a));
//    cout << K << '\n';
    forn(i, K) cout << a[a.size() - i - 1] << ' ';
    cout << '\n';

    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}