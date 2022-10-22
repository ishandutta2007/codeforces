#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;
#define int long long

bool comp(pair <int, int> a, pair <int, int> b) {
    return a.first - a.second > b.first - b.second;
}

const int MAXN = 1e5 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a1, b1;
    cin >> n >> a1 >> b1;

    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        
    sort(a.begin(), a.end(), comp);
    
    int st = 0;
    for (int i = 0; i < n; ++i) st += a[i].second;

    int add = 0;
    for (int i = 0; i < min(n, b1); ++i) {
        add += max(0ll, a[i].first - a[i].second);
    }
    
    int ans = st;
    for (int i = 0; i < min(n, b1); ++i) {
        ans += max(0ll, a[i].first - a[i].second);
    }
    
    if (b1) {
        for (int i = 0; i < n; ++i) {
            int x = max(0ll, a[i].first * (1 << a1) - a[i].second);
            if (i < min(n, b1)) ans = max(ans, st + add - max(0ll, a[i].first - a[i].second) + x);
            else ans = max(ans, st + add - max(0ll, a[min(n, b1) - 1].first - a[min(n, b1) - 1].second) + x);
        }
    }
    
    cout << ans << '\n';
    return 0;
}