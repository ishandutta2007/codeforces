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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    int m = n - 1;
    vector <ll> t(m), w(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> w[i];
    }
    vector <int> idx;
    for (int i = 0; i < m; ++i) idx.push_back(i);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return t[i] > t[j];
    });
    int low = 0, high = n;
    while (high - low > 1) {
        ll ta = a, tb = b;
        int mid = (low + high) >> 1;
        multiset <ll> we;
        int uk = 0;
        while (uk < m && t[idx[uk]] > a) {
            we.insert(w[idx[uk]] - t[idx[uk]] + 1);
            ++uk;
        }
        while (we.size() >= mid) {
            ll cw = *we.begin();
            if (a >= cw) {
                a -= cw;
                we.erase(we.begin());
                while (uk < m && t[idx[uk]] > a) {
                    we.insert(w[idx[uk]] - t[idx[uk]] + 1);
                    ++uk;
                }
            }
            else {
                break;
            }
        }
        a = ta;
        b = tb;
        if (we.size() < mid) high = mid;
        else low = mid;
    }
    cout << high << '\n';
}