#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;

struct event {
    int time, num, type;
    bool operator <(const event &other) const {
        if (time != other.time) return time < other.time;
        if (type != other.type) return type > other.type;
        return num < other.num;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int s, f;
    cin >> s >> f;
    --s, --f;
    vector <event> e;
    for (int i = 0; i < n; ++i) {
        int ts = (s - i + n) % n;
        int tf = (f - i + n) % n;
        if (tf >= ts) {
            e.push_back({ts, a[i], -1});
            e.push_back({tf, a[i], 1});
        }
        else {
            e.push_back({ts, a[i], -1});
            e.push_back({n, a[i], 1});
            e.push_back({0, a[i], -1});
            e.push_back({tf, a[i], 1});
        }
    }
    ll bal = 0;
    int time = -1;
    ll best = -1;
    sort(e.begin(), e.end());
    for (auto ev : e) {
        if (ev.type == -1) {
            bal += ev.num;
        }
        else {
            bal -= ev.num;
        }
        if (bal > best) {
            best = bal;
            time = ev.time;
        }
    }
    cout << time + 1 << endl;
}