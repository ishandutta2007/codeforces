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
    ll n;
    cin >> n;
    ll x1, x2;
    cin >> x1 >> x2;
    vector <pair <ll, ll>> events;
    for (int i = 0; i < n; ++i) {
        int k, b;
        cin >> k >> b;
        events.emplace_back(k * x1 + b, k * x2 + b);
    }
    sort(events.begin(), events.end());
    for (int i = 0; i + 1 < events.size(); ++i) {
        if (events[i + 1].second < events[i].second) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}