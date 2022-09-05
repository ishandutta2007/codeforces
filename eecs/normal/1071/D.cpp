#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int T, tot, prod, mn[1000010];
bool solved[10000][11];
bitset<1000> b[10000][11];
vector<int> V, prime;
unordered_map<int, int> id;

int main() {
    scanf("%d", &T);
    for (int i = 2; i <= N; i++) if (!mn[i]) {
        if (prime.size() < 1000) prime.push_back(i);
        for (int j = i; j <= N; j += i) mn[j] = i;
    }
    auto get = [&](long long x) {
        V.clear();
        int lst = 50;
        while (x > 1) {
            int c = 0, t = x <= N ? mn[x] : 0;
            if (!t) {
                for (int i = lst; ~i; i--) {
                    if (!(x % prime[i])) { t = prime[i], lst = i; break; }
                }
            }
            while (!(x % t)) x /= t, c++;
            V.push_back(c);
        }
        sort(V.begin(), V.end(), greater<int>());
        int z = prod = 1;
        for (int i = 0; i < V.size(); i++) {
            prod *= V[i] + 1;
            for (int j = 0; j < V[i]; j++) z *= prime[i];
        }
        return z;
    };
    for (int i = 1; i <= N; i++) {
        if (i == get(i)) id[i] = ++tot;
    }
    function<void(int, int)> solve = [&](int x, int step) {
        int y = get(x);
        if (prod >= 1000) return;
        if (!id.count(x)) id[x] = ++tot;
        int $ = id[x];
        if (solved[$][step]) return;
        solved[$][step] = 1;
        if (!step) { b[$][step][prod] = 1; return; }
        vector<int> V2 = V;
        for (int i = 0; i < V2.size(); i++) {
            int v = get(x / prime[i]);
            solve(v, step - 1), b[$][step] |= b[id[v]][step - 1];
            v = get(1LL * x * prime[i]);
            if (v <= N * 100) solve(v, step - 1), b[$][step] |= b[id[v]][step - 1];
        }
        int v = get(1LL * x * prime[V2.size()]);
        if (v <= N * 100) solve(v, step - 1), b[$][step] |= b[id[v]][step - 1];
    };
    for (int i = 1; i <= N; i++) if (id[i]) {
        for (int j = 0; j <= 10; j++) solve(i, j);
    }
    while (T--) {
        int x, y, ans = INT_MAX;
        scanf("%d %d", &x, &y);
        x = get(x), y = get(y);
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 10; j++) if (i + j < ans) {
                if ((b[id[x]][i] & b[id[y]][j]).any()) ans = min(ans, i + j);
            }
        }
        assert(ans <= 10);
        printf("%d\n", ans);
    }
    return 0;
}