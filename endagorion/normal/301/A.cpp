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
    vector<int> a(2 * N - 1);
    int sum = 0, mmod = 1e9, mneg = 0;
    for (int i = 0; i < 2 * N - 1; ++i) {
        cin >> a[i];
        sum += abs(a[i]);
        if (a[i] <= 0) {
            ++mneg;
        }
        mmod = min(mmod, abs(a[i]));
    }
    if (N % 2 == 1 || mneg % 2 == 0) {
        cout << sum << '\n';
    } else {
        cout << sum - 2 * mmod << '\n';
    }

	return 0;
}