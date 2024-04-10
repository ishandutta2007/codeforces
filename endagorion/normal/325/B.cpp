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

    long long N;
    cin >> N;
    vector<long long> ans;
    for (int k = 0; k <= 60; ++k) {
        long long l = 0, r = min(3e9, 5e18 / (1LL << k));
        while (r - l > 1) {
            long long m = (l + r) / 2;
            long long f = m * ((1LL << k) - 1) + m * (m - 1) / 2;
            if (f > N) {
                r = m;
            } else {
                l = m;
            }
        }
        if (l % 2 == 1 && l * ((1LL << k) - 1) + l * (l - 1) / 2 == N) {
            ans.pb(l << k);
        }
    }

    sort(all(ans));
    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << '\n';
        }
    }

	return 0;
}