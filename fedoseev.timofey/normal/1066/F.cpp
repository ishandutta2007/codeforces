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

int dist(pair <int, int> &a, pair <int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    map <int, vector <pair <int, int>>> kek;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	cin >> x >> y;
    	kek[max(x, y)].emplace_back(x, y);
    }
    ll ans = 0;
    for (auto &p : kek) {
    	int cur = p.first;
    	sort(p.second.begin(), p.second.end(), [&] (pair <int, int> a, pair <int, int> b) {
    		if (a.second == cur && b.first == cur) return true;
    		if (a.first == cur && b.second == cur) return false;
    		if (a.first == cur && b.first == cur) {
    			return a.second > b.second;
    		}
    		return a.first < b.first;
    	});
    }
    vector <ll> cnt(kek.size());
    int j = 0;
    for (auto &p : kek) {
    	ll cur = 0;
    	for (int i = 0; i + 1 < p.second.size(); ++i) {
    		cur += dist(p.second[i], p.second[i + 1]);
    	}
    	cnt[j] = cur;
    	++j;
    }
    vector <pair <int, int>> a;
    vector <pair <int, int>> b;
    a.push_back({0, 0});
    b.push_back({0, 0});
    for (auto &p : kek) {
    	a.push_back(p.second.front());
    	b.push_back(p.second.back());
    }
    ll c1 = 0, c2 = 0;
    for (int i = 1; i < a.size(); ++i) {
    	ll tc1 = c1, tc2 = c2;
    	c1 = min(tc1 + dist(a[i - 1], b[i]) + cnt[i - 1], tc2 + dist(b[i - 1], b[i]) + cnt[i - 1]);
    	c2 = min(tc2 + dist(b[i - 1], a[i]) + cnt[i - 1], tc1 + dist(a[i - 1], a[i]) + cnt[i - 1]);
    }
    cout << min(c1, c2) << '\n';
}