#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

bool cmp(pair< int, int > a, pair< int, int > b) {
    return a.second < b.second;
}

const long long MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector< pair< int, int > > s(m);
    vector< int > q;
    for (int i = 0; i < m; ++i) {
        cin >> s[i].first >> s[i].second;
        q.push_back(s[i].first);
        q.push_back(s[i].second);
    }
    sort(q.begin(), q.end());
    q.resize(unique(q.begin(), q.end()) - q.begin());
    for (int i = 0; i < m; ++i) {
        s[i].first = lower_bound(q.begin(), q.end(), s[i].first) - q.begin();
        s[i].second = lower_bound(q.begin(), q.end(), s[i].second) - q.begin();
    }
    vector< long long > ways(q.size(), 0);
    vector< long long > sums(q.size(), 0);
    if (m == 0 || q[0] != 0 || q[q.size() - 1] != n) {
        cout << 0 << '\n';
        return 0;
    }
    sort(s.begin(), s.end(), cmp);
    ways[0] = 1;
    sums[0] = 1;
    int last = 0;
    for (int i = 0; i < m; ++i) {
        while (last + 1 < s[i].second) {
            ++last;
            sums[last] = (sums[last - 1] + ways[last]) % MOD;
        }
        long long add = sums[s[i].second - 1];
        if (s[i].first > 0) {
            add = (add + MOD - sums[s[i].first - 1]) % MOD;
        }
        ways[s[i].second] = (ways[s[i].second] + add) % MOD;
    }
    cout << ways[q.size() - 1] << '\n';
    
    return 0;
}