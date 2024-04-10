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
    vector<int> a(N), next(N), prev(N);
    vector<bool> alive(N, true);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        next[i] = i + 1;
        prev[i] = i - 1;
    }
    vector<int> q;
    for (int i = 0; i < N; ++i) {
        if (next[i] < N && a[i] > a[next[i]]) {
            q.pb(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        vector<int> qq;
        bool ch = false;
        for (int i = 0; i < q.size(); ++i) {
            if (alive[q[i]]) {
                bool k = false;
                while (next[q[i]] < N && a[q[i]] > a[next[q[i]]]) {
                    int m = next[q[i]];
                    int n = next[m];
                    alive[m] = false;
                    next[q[i]] = n;
                    k = true;
                    ch = true;
                    if (n < N && a[m] < a[n]) {
                        break;
                    }
                }
                if (k) {
                    qq.pb(q[i]);
                }
            }
        }
        if (!ch) {
            break;
        }
        q = qq;
        ++ans;
    }

    cout << ans << '\n';

	return 0;
}