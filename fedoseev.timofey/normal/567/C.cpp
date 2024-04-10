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

const int Inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    map <int, vector <int>> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        x[y].push_back(i);
        a[i] = y;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (a[i] % k) continue;
        ll pr = a[i] / k;
        ll nx = (ll)a[i] * k;
        if (abs(nx) > Inf) continue;
        ans += (ll)(lower_bound(x[pr].begin(), x[pr].end(), i) - x[pr].begin()) * ((int)x[nx].size() - (upper_bound(x[nx].begin(), x[nx].end(), i) - x[nx].begin()));
    }
    cout << ans << '\n';
}