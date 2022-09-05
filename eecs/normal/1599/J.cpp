#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, b[maxn], a[maxn], coef[maxn];
bool mark[maxn];
mt19937 rnd(time(0));
vector<pair<int, int>> V[27];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    auto print = [&](vector<int> V) {
        vector<int> ans;
        if (V.size() & 1) {
            assert(V.size() == 3);
            int s = (b[V[0]] + b[V[1]] + b[V[2]]) / 2;
            ans.push_back(s - b[V[0]]);
            ans.push_back(s - b[V[1]]);
            ans.push_back(s - b[V[2]]);
        } else {
            ans.push_back(0);
            for (int i = 0; i + 1 < V.size(); i++) {
                ans.push_back(b[V[i]] - ans.back());
            }
        }
        for (int i : V) mark[i] = 1;
        for (int i = 0; i < n; i++) {
            if (!mark[i]) ans.push_back(b[i] - ans[0]);
        }
        puts("YES");
        for (int x : ans) printf("%d ", x);
        exit(0);
    };
    for (int i = 0; i < n; i++) if (!(b[i] % 2)) {
        int odd = 0, even = 0;
        for (int j = 0; j < n; j++) if (i ^ j) {
            if (b[j] % 2) odd++;
            else even++;
        }
        if (odd > 1) {
            vector<int> V = {i};
            for (int j = 0; j < n; j++) if (i ^ j) {
                if (b[j] % 2 && V.size() < 3) V.push_back(j);
            }
            print(V);
        } else if (even > 1) {
            vector<int> V = {i};
            for (int j = 0; j < n; j++) if (i ^ j) {
                if (!(b[j] % 2) && V.size() < 3) V.push_back(j);
            }
            print(V);
        }
    }
    shuffle(b, b + n, rnd);
    int m = min(26, n), mid = m / 2, all = 0;
    for (int i = 0; i < mid; i++) {
        all = all * 3 + 1;
    }
    function<void(int, int, int, int)> dfs1 = [&](int i, int sum, int cnt, int mask) {
        if (i == mid) {
            V[cnt].emplace_back(sum, mask); return;
        }
        for (int x : {-1, 0, 1}) {
            dfs1(i + 1, sum + x * b[i], cnt + x, mask * 3 + x + 1);
        }
    };
    dfs1(0, 0, mid, 0);
    for (int i = 0; i <= 2 * mid; i++) {
        sort(V[i].begin(), V[i].end());
    }
    function<void(int, int, int, bool)> dfs2 = [&](int i, int sum, int cnt, bool used) {
        if (i == m) {
            if (-cnt < -mid || -cnt > mid) return;
            int k = mid - cnt;
            auto it = lower_bound(V[k].begin(), V[k].end(), make_pair(-sum, 0));
            if (it != V[k].end() && !used && it->second == all) it++;
            if (it == V[k].end() || it->first != -sum) return;
            for (int i = mid - 1, mask = it->second; ~i; i--) {
                coef[i] = mask % 3 - 1, mask /= 3;
            }
            vector<int> V1, V2;
            for (int i = 0; i < n; i++) {
                if (coef[i] == 1) V1.push_back(i);
                if (coef[i] == -1) V2.push_back(i);
            }
            assert(V1.size() == V2.size());
            vector<int> V;
            for (int i = 0; i < V1.size(); i++) {
                V.push_back(V1[i]), V.push_back(V2[i]);
            }
            print(V);
        }
        for (int x : {-1, 0, 1}) {
            coef[i] = x, dfs2(i + 1, sum + x * b[i], cnt + x, used | (x != 0));
        }
    };
    dfs2(mid, 0, 0, 0), puts("NO");
    return 0;
}