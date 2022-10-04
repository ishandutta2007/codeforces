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

const int md = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int ans = 1;
    set <int> L, R, M;
    for (int i = 0; i < n; ++i) {
        string s; int x;
        cin >> s >> x;
        if (s == "ADD") {
            if (!R.empty() && (*R.begin()) < x) R.insert(x);
            else if (!L.empty() && (*L.rbegin()) > x) L.insert(x);
            else M.insert(x);
        }
        else {
            if (L.count(x)) {
                if ((*L.rbegin()) != x) {
                    cout << "0\n";
                    return 0;
                }
                else {
                    L.erase(--L.end());
                    for (auto e : M) R.insert(e);
                    M.clear();
                }
            }
            else if (R.count(x)) {
                if ((*R.begin()) != x) {
                    cout << "0\n";
                    return 0;
                }
                else {
                    R.erase(R.begin());
                    for (auto e : M) L.insert(e);
                    M.clear();
                }
            }
            else {
                ans = mul(ans, 2);
                for (auto e : M) {
                    if (e < x) L.insert(e);
                    else if (e > x) R.insert(e);
                }
                M.clear();
            }
        }
    }
    ans = mul(ans, M.size() + 1);
    cout << ans << '\n';
}