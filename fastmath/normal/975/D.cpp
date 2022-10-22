#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

int st[MAXN], tx[MAXN], ty[MAXN];

map <int, int> ms1;
map <pair <int, int>, int> ms2;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) cin >> st[i] >> tx[i] >> ty[i];

    for (int i = 0; i < n; ++i) ++ms1[a * tx[i] - ty[i]];
    for (int i = 0; i < n; ++i) ++ms2[{tx[i], ty[i]}];

    int ans = 0;
    for (pair <int, int> elem : ms1) ans += elem.second * (elem.second - 1);
    for (auto elem : ms2) ans -= elem.second * (elem.second - 1);

    cout << ans << '\n';
    return 0;
}