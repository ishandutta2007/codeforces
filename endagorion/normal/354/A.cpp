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
    int N, l, r, Ql, Qr;
    cin >> N >> l >> r >> Ql >> Qr;
    vector<int> a(N), p(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }
    long long ans = 1e18;
    for (int i = 0; i <= N; ++i) {
        long long res = l * p[i] + r * (p[N] - p[i]);
        int lc = i, rc = N - i;
        if (lc < rc) {
            res += Qr * max(rc - lc - 1, 0);
        } else {
            res += Ql * max(lc - rc - 1, 0);
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
	return 0;
}