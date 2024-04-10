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

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAXN = 1500000;
int maxMove[MAXN];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    int A, B;
    cin >> B >> A;
    for (int i = 0; i < x.size(); ++i) {
        int y = x[i];
        if (B - B % y >= A) {
            maxMove[B - A] = max(maxMove[B - A], B % y);
        }
        for (int k = (B / y) * y - 1; k > A; k -= y) {
            if (k - (y - 1) >= A) {
                maxMove[k - A] = max(maxMove[k - A], y - 1);
            }
        }
    }
    for (int i = B - A; i > 0; --i) {
        maxMove[i - 1] = max(maxMove[i - 1], maxMove[i] - 1);
    }
    int ans = 0;
    int k = B;
    while (k > A) {
        k -= max(maxMove[k - A], 1);
        ++ans;
    }
    cout << ans << '\n';

	return 0;
}