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
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    vector<long long> ans(N);
    ans[N - 1] = 0;
    vector<int> ch;
    ch.pb(N - 1);
    size_t cur = 0;
    for (int k = N - 2; k >= 0; --k) {
        while (cur + 1 < ch.size()) {
            int j = ch[cur + 1], jj = ch[cur];
            if (a[j] * b[k] + ans[j] < a[jj] * b[k] + ans[jj]) {
                ++cur;
            } else {
                break;
            }
        }

        ans[k] = a[ch[cur]] * b[k] + ans[ch[cur]];

        while (ch.size() > 1) {
            int j = ch.back(), jj = ch[ch.size() - 2];
            if (1.0 * (ans[k] - ans[jj]) / (a[k] - a[jj]) > 1.0 * (ans[j] - ans[jj]) / (a[j] - a[jj])) {
                ch.pop_back();
            } else {
                break;
            }
        }
        cur = min(cur, ch.size() - 1);
        ch.push_back(k);
    }

    cout << ans[0] << '\n';

	return 0;
}