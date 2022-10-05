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

const int N = 1e5 + 7;

int ps[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, p;
    cin >> n >> p;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= p;
    }
    ps[0] = 0;
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, ps[i] % p + (ps[n] - ps[i]) % p);
    }
    cout << ans << "\n";
}