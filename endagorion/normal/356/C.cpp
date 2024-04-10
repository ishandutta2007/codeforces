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

int a[5];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    /*if (!a[1] && !a[2]) {
        cout << 0 << '\n';
    }*/
    int ans = 1e9;
    for (int b2 = 0; b2 <= a[1] + a[2]; ++b2) {
        if (3 * b2 > 2 * a[2] + a[1] + a[4]) {
            continue;
        }
        int b1 = max(0, b2 - a[2]);
        int b3 = max(0, 2 * a[2] + a[1] - 3 * b2);
        if (b1 <= a[1] && b2 <= b1 + a[2] && b3 <= b2 + a[3]) {
            ans = min(ans, b1 + b2 + b3);
        }
    }
    if (ans > 1e8) {
        ans = -1;
    }
    cout << ans << '\n';

	return 0;
}