#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define INF 2000000005
#define MN 1000000
#define MM 40
#define ll long long
using namespace std;
inline int read() {
    int x; scanf("%d", &x);
    return x;
}
char op[5];
bool b[MM + 5];
int n, A = 1, B, P, M, N;
ll mm[MM + 5], pmm[MM + 5], smm[MM + 5], ori = 1, sa[MM + 5];
vector<ll> s[MM + 5], v[MM + 5];
ll ans = 0, dif[MM + 5];

void evaluate(int bb) {
    int max_p = min(A, bb / P); ll t = 0;
    pmm[0] = 1; ll all_m = 1;
    for (int i = 1; i <= N; ++i) {
        pmm[i] = pmm[i - 1];
        if (!b[i]) {
            pmm[i] *= mm[i];
        } else {
            all_m *= mm[i];
        }
    }
    smm[N] = 1;
    for (int i = N - 1; i >= 0; --i) {
        smm[i] = smm[i + 1];
        if (!b[i + 1]) {
            smm[i] *= mm[i + 1];
        }
    }
    for (int i = 0; i <= N; ++i) {
        t += 1LL * smm[i] * sa[i] * all_m;
        // cout << "add" << i << " " << t << " " << smm[i] << " " << sa[i] << " " << all_m << endl;
        dif[i] = 1LL * (pmm[i] - 1) * smm[i] * all_m;
    }
    ll l = 0, r = 2e18, mid, res = 0, sum = 0, cs = max_p;
    while (l <= r) {
        mid = l + r >> 1;
        int chosen = 0;
        ll cur_sum = 0;
        for (int i = 0; i <= N; ++i) if(v[i].size()) {
            int t;
            if (mid > 0 && dif[i] > 0) {
                t = lower_bound(v[i].begin(), v[i].end(), (mid + dif[i] - 1) / dif[i]) - v[i].begin();
            } else if (mid == 0) {
                t = 0;
            } else {
                t = v[i].size();
            }
            // cout << i << " at " << t << " of " << v[i].size() << endl;
            chosen += v[i].size() - t;
            if (t < v[i].size()) {
                cur_sum += s[i][t] * dif[i];
            }
        }
        if (chosen >= max_p) {
            res = mid;
            l = mid + 1;
            sum = cur_sum;
            cs = chosen;
        } else {
            r = mid - 1;
        }
    }
    // cout << bb << " " << t << " " << sum << " " << res << " " << cs << " " << max_p << endl;
    ans = max(ans, t + sum - res * (cs - max_p));
}

void dfs(int x, int bb, int k) {
    if (x == 0) {
        evaluate(bb);
        return;
    }
    if (mm[x] < k) {
        b[x] = 0;
        dfs(x - 1, bb, k);
    }
    if (bb >= M) {
        b[x] = 1;
        dfs(x - 1, bb - M, min(k, static_cast<int>(mm[x])));
    }
}

int main() {
    n = read(); B = read(); P = read(); M = read();
    v[0].push_back(1); sa[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%s%d", op, &x);
        if (op[0] == '+') {
            v[N].push_back(x);
            ori += x;
            ++A; sa[N] += x;
        } else if (x > 1) {
            mm[++N] = x;
            ori *= x;
        }
    }
    ans = ori;
    for (int i = 0; i <= N; ++i) {
        if (!v[i].size()) continue;
        sort(v[i].begin(), v[i].end());
        s[i].resize(v[i].size());
        s[i][v[i].size() - 1] = v[i][v[i].size() - 1];
        for (int j = v[i].size() - 2; j >= 0; --j) {
            s[i][j] = s[i][j + 1] + v[i][j];
        }
    }
    dfs(N, B, INF);
    cout << ans;
    return 0;
}