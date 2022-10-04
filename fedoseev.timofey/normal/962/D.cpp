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
    int n;
    cin >> n;
    map <ll, set <int>> num;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num[x].insert(i);
    }
    ll f = 0;
    for (auto &p : num) {
        ll cur = p.first;
        while (p.second.size() >= 2) {
            ll a = *p.second.begin();
            p.second.erase(p.second.begin());
            ll b = *p.second.begin();
            p.second.erase(p.second.begin());
            num[2 * cur].insert(b);
        }
    }
    vector <pair <int, ll>> ans;
    for (auto &p : num) {
        for (int i : p.second) {
            ans.push_back({i, p.first});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].second << ' ';
    }
}