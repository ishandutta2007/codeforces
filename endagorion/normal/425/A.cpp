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

int a[300];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    cin >> N >> K;
    forn(i, N) cin >> a[i];
    int ans = -1e9;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            multiset<int> del, add;
            int sum = 0;
            forn(k, N) {
                if (k >= i && k <= j) {
                    del.insert(a[k]);
                    sum += a[k];
                    if (del.size() > K) {
                        del.erase(--del.end());
                    }
                } else {
                    add.insert(a[k]);
                    if (add.size() > K) {
                        add.erase(add.begin());
                    }
                }
            } 
            while (!add.empty() && !del.empty() && *add.rbegin() > *del.begin()) {
                sum += *add.rbegin() - *del.begin();
                add.erase(--add.end());
                del.erase(del.begin());
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}