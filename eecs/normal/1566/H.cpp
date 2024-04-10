#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, cur, bel[maxn], f[maxn], ans[maxn];
int a[20], id[20];
vector<int> cand, nums[maxn], mask[maxn];
mt19937 rnd(time(0));

bool ins(int x) {
    int o = x;
    for (int i = 0; i < 20; i++) if (x >> i & 1) {
        if (!a[i]) { a[i] = x, id[i] = o; return 1; }
        x ^= a[i];
        for (int j : mask[id[i]]) mask[o].push_back(j);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    iota(bel + 1, bel + n + 1, 1);
    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += i * i) {
            while (!(bel[j] % (i * i))) bel[j] /= i;
        }
    }
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        if (i == bel[i]) V.push_back(i);
        nums[bel[i]].push_back(i);
    }
    cout << V.size();
    for (int x : V) cout << " " << x;
    cout << endl;
    for (int x : V) {
        cin >> f[x];
    }
    for (int x : V) {
        for (int y = x + x; y <= n; y += x) {
            if (y == bel[y]) f[y] ^= f[x];
        }
    }
    reverse(V.begin(), V.end());
    for (int x : V) {
        for (int y = x + x; y <= n; y += x) f[x] ^= f[y];
    }
    for (int x : V) {
        memset(a, 0, sizeof(a));
        memset(id, 0, sizeof(id));
        for (int y : nums[x]) {
            if (!ins(y)) cand.push_back(y);
            mask[y].push_back(y);
            sort(mask[y].begin(), mask[y].end());
            vector<int> V;
            for (int z : mask[y]) {
                if (V.empty() || z ^ V.back()) V.push_back(z);
                else V.pop_back();
            }
            mask[y] = V;
        }
        for (int i = 0; i < 20; i++) if (f[x] >> i & 1) {
            f[x] ^= a[i];
            for (int j : mask[id[i]]) {
                cur -= ans[j], cur += (ans[j] ^= 1);
            }
        }
    }
    while (cur ^ m) {
        int x = cand[rnd() % cand.size()], o = cur;
        for (int z : mask[x]) {
            cur -= ans[z], cur += (ans[z] ^= 1);
        }
        if (abs(cur - m) > abs(o - m)) {
            cur = o;
            for (int z : mask[x]) ans[z] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}