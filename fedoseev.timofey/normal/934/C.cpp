#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;
vector <int> cnt;

const int Inf = 1e9;

int countOne(int l, int r) {
    return r - l - cnt[r] + cnt[l];
}

int countTwo(int l, int r) {
    return r - l - countOne(l, r);
}

int countSecond(int l, int r) {
    return countTwo(l, r) - countOne(l, r);
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cnt.resize(n + 1);
    cnt[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1] + (a[i - 1] == 2);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, countOne(0, i) + countTwo(i, n));
    }
    for (int l = 0; l < n; ++l) {
        int cur = -Inf;
        for (int r = l; r < n; ++r) {
            cur = max(cur, countSecond(l, r + 1));
            ans = max(ans, countOne(l, r + 1) + cur + countOne(0, l) + countTwo(r + 1, n));
        }
    }
    cout << ans << endl;
}