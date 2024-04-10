#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n, mm;
vector<int> v;
unordered_map<int, vector<int> > m;
set<int> s;
unordered_map<int, bool> m1;


int main() {
    cin >> n >> mm;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        m1[x] = 1;
        v.push_back(x);
    }
    for (int i = 0; i < mm; i++) {
        int u, t;
        scanf("%d %d", &u, &t);
        m[u + t].push_back(u - t);
        v.push_back(u - t);
        v.push_back(u + t);
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (m1[v[i]]) {
            s.insert(v[i]);
        }
        for (int j = 0; j < (int)m[v[i]].size(); j++) {
            set<int>:: iterator it = s.lower_bound(m[v[i]][j]);
            if (it != s.end() && *it <= v[i]) {
                s.erase(*it);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}