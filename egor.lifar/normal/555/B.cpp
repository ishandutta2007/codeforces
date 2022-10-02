#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


int n, m;
long long l[200001], r[200001];
vector<pair<pair<long long, long long>, int> > v;
vector<pair<long long, int> > g;
int ans[200001];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &l[i], &r[i]);
        if (i > 0) {
            v.push_back(make_pair(make_pair(l[i] - r[i - 1], r[i] - l[i - 1]), i - 1));
        }
    }
    sort(v.begin(), v.end());
    g.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &g[i].first);
        g[i].second = i + 1;
    }
    sort(g.begin(), g.end());
    int ll = 0;
    set<pair<long long, long long> > s;
    for (int q = 0; q < (int)g.size(); q++) {
        while (ll < (int)v.size() && v[ll].first.first <= g[q].first) {
            s.insert(make_pair(v[ll].first.second, v[ll].second));
            ll++;
        }
        auto it = s.lower_bound(make_pair(g[q].first, -1));
        if (it != s.end()) {
            ans[it->second] = g[q].second;
            s.erase(it);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}