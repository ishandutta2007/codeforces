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
    int n, w;
    cin >> n >> w;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = w;
    int delta = 0;
    for (int i = 0; i < n; ++i) {
        delta += a[i];
        l = max(l, -delta);
        r = min(r, w - delta);
    }
    cout << max(0, r - l + 1) << '\n';
}