#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll lim = 1e14, B = 1e7;
ll n, K;
int type[B + 10];
unordered_map<ll, vector<int>> mp[10][2];

int main() {
    scanf("%lld %lld", &n, &K);
    for (int i = 1; i < B; i++) {
        int x = i / 10 % 10, y = i % 10;
        if (x == y) continue;
        int op = x < y ? 1 : -1;
        if (i < 100) type[i] = op;
        else if (type[i / 10] == -op) type[i] = op;
        if (type[i] && i % n == 0) {
            if (!--K) printf("%d\n", i), exit(0);
        }
    }
    for (int i = B / 100; i < B; i++) {
        if (type[i]) mp[i / (B / 10)][type[i] == 1][i % n].push_back(i);
    }
    for (int i = 1; i < B; i++) if (type[i]) {
        int op = type[i] == 1;
        ll h = (n - 1LL * i * B % n) % n;
        int l = op || i < 10 ? 0 : i % 10 + 1;
        int r = !op || i < 10 ? 9 : i % 10 - 1;
        for (int j = l; j <= r; j++) {
            int z = j > i % 10;
            if (i == j || mp[j][z].find(h) == mp[j][z].end()) continue;
            int sz = mp[j][z][h].size();
            if (sz >= K) printf("%lld\n", mp[j][z][h][K - 1] + 1LL * i * B), exit(0);
            K -= sz;
        }
    }
    puts("-1");
    return 0;
}