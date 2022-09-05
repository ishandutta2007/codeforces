#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, xors, nS[30];
map<int, set<int>> mp;
map<int, int> sg;

int main() {
    scanf("%d", &n);
    while (n--) {
        int x; scanf("%d", &x);
        for (int i = 2; i * i <= x; i++) if (!(x % i)) {
            int cnt = 0;
            while (!(x % i)) x /= i, cnt++;
            mp[i].insert(cnt);
        }
        if (x > 1) mp[x].insert(1);
    }
    function<int(int)> solve = [&](int S) {
        if (S <= 1) return 0;
        if (sg.count(S)) return sg[S];
        set<int> T;
        for (int i = 1; i < 30; i++) if (S >= (1 << i)) {
            int nS = 0;
            for (int j = 0; j < 30; j++) if (S >> j & 1) {
                if (j < i) nS |= 1 << j;
                else nS |= 1 << (j - i);
            }
            T.insert(solve(nS));
        }
        int x = 0;
        while (T.count(x)) x++;
        return sg[S] = x;
    };
    for (auto &p : mp) {
        sg.clear();
        int S = 0;
        for (auto &x : p.second) S |= 1 << x;
        xors ^= solve(S);
    }
    puts(xors ? "Mojtaba" : "Arpa");
    return 0;
}