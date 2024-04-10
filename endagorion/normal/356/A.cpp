#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
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

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    cin >> N >> M;
    vector<pair<int, pii> > a;
    for (int i = 0; i < M; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        --x;
        a.pb(mp(l, mp(-i, -x - 1)));
        a.pb(mp(x, mp(-i, x)));
        a.pb(mp(x + 1, mp(-i, -x-1)));
        a.pb(mp(r, mp(-i, x)));
    }
    sort(all(a));
    size_t j = 0;
    multiset<pii> c;
    for (int i = 0; i < N; ++i) {
        while (j < a.size() && a[j].first == i) {
            int k = a[j].second.first, x = a[j].second.second;
            if (x < 0) {
                c.insert(mp(k, - x - 1));
            } else {
                c.erase(mp(k, x));
            }
            ++j;
        }
        int x = -1;
        if (!c.empty()) {
            x = c.rbegin()->second;
        }
        printf("%d ", x + 1);
    }
    printf("\n");

	return 0;
}