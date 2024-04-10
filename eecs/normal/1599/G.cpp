#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, ano, ver, x[maxn], y[maxn], perm[maxn];
mt19937 rnd(time(0));
vector<int> id, path;
double ans = 1e18;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    auto dist = [&](int i, int j) {
        return sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]));
    };
    if (n <= 5) {
        iota(perm + 1, perm + n + 1, 1);
        do {
            if (perm[1] ^ K) continue;
            double sum = 0;
            for (int i = 1; i < n; i++) sum += dist(perm[i], perm[i + 1]);
            ans = min(ans, sum);
        } while (next_permutation(perm + 1, perm + n + 1));
        printf("%.9f\n", ans), exit(0);
    }
    vector<array<int, 3>> slope;
    while (1) {
        slope.clear(), ver = rnd() % n + 1;
        for (int i = 1; i <= n; i++) if (i ^ ver) {
            int p = x[i] - x[ver], q = y[i] - y[ver];
            if (!p && !q) assert(0);
            int g = __gcd(p, q);
            p /= g, q /= g;
            if (p < 0 || !p && q < 0) p *= -1, q *= -1;
            slope.push_back({p, q, i});
        }
        sort(slope.begin(), slope.end());
        if (slope[0][0] != slope[1][0] || slope[0][1] != slope[1][1]) {
            ano = slope[0][2], slope.erase(slope.begin());
        } else {
            ano = slope.back()[2], slope.erase(--slope.end());
        }
        if (slope[0][0] == slope.back()[0] && slope[0][1] == slope.back()[1]) break;
    }
    auto chk = [&](vector<int> path) {
        double sum = 0;
        for (int i = 0; i + 1 < path.size(); i++) {
            sum += dist(path[i], path[i + 1]);
        }
        for (int i = 0; i + 1 < path.size(); i++) {
            ans = min(ans, sum - dist(path[i], path[i + 1]) + dist(path[i], ano) + dist(ano, path[i + 1]));
        }
        ans = min(ans, sum + dist(path.back(), ano));
    };
    id.push_back(ver);
    for (auto &p : slope) {
        id.push_back(p[2]);
    }
    sort(id.begin(), id.end(), [&](int i, int j) {
        return make_pair(x[i], y[i]) < make_pair(x[j], y[j]);
    });
    if (K == ano) {
        double sum = 0;
        for (int i = 0; i + 1 < id.size(); i++) {
            sum += dist(id[i], id[i + 1]);
        }
        for (int i = 0; i + 1 < id.size(); i++) {
            ans = min(ans, sum - dist(id[i], id[i + 1]) + dist(id[i], ano) + dist(id[0], id[i + 1]));
            ans = min(ans, sum - dist(id[i], id[i + 1]) + dist(id[i + 1], ano) + dist(id[i], id.back()));
        }
        ans = min(ans, sum + dist(id[0], K));
        ans = min(ans, sum + dist(id.back(), K));
    } else {
        int pos = find(id.begin(), id.end(), K) - id.begin();
        for (int i = pos; ~i; i--) path.push_back(id[i]);
        for (int i = pos + 1; i < id.size(); i++) path.push_back(id[i]);
        chk(path), path.clear();
        for (int i = pos; i < id.size(); i++) path.push_back(id[i]);
        for (int i = pos - 1; ~i; i--) path.push_back(id[i]);
        chk(path), path = {K};
        for (int i = 0; i < id.size(); i++) if (i ^ pos) path.push_back(id[i]);
        chk(path), path = {K};
        for (int i = id.size() - 1; ~i; i--) if (i ^ pos) path.push_back(id[i]);
        chk(path);
    }
    printf("%.9f\n", ans);
    return 0;
}