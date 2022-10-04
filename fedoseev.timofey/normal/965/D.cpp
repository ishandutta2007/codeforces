#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int w, l;
    cin >> w >> l;
    --w;
    vector <int> a(w);
    vector <int> cur(w);
    for (int i = 0; i< w; ++i) cin >> a[i];
    int r = 0;
    for (int i = 0; i < l; ++i) cur[i] = a[i];
    for (int i = 0; i < w; ++i) {
        while (cur[i] && r < w && r <= i + l) {
            r = max(r, i + 1);
            if (a[r] - cur[r] > 0) {
                int can = a[r] - cur[r];
                can = min(can, cur[i]);
                cur[i] -= can;
                cur[r] += can;
            }
            if (a[r] - cur[r] == 0) ++r;
        }
    }
    int ans = 0;
    for (int i = w - l; i < w; ++i) {
        ans += cur[i];
    }
    cout << ans << '\n';
}