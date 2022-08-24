#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N;
    cin >> N;
    vector< pair<long long, long long> > a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    long long count = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            long long d = 1LL << (2 * min(a[i].first - a[i - 1].first, 30LL));
            count = (count + d - 1) / d;
        }
        count = max(a[i].second, count);
    }
    int ans = a.back().first;
    if (count == 1) {
        ++ans;
    }
    while (count > 1) {
        ++ans;
        count = (count + 3) / 4;
    }
    cout << ans << '\n';

    return 0;
}