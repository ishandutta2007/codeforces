#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, p[maxn];
mt19937 rnd(time(0));
vector<int> V[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    auto ask = [&](int a, int b, int c) {
        cout << "? " << a << " " << b << " " << c << endl;
        return cin >> a, a;
    };
    while (T--) {
        cin >> n;
        int p1, p2, mx = 0;
        for (int $ = 1, a, b, c; $ <= 400; $++) {
            do {
                a = rnd() % n + 1, b = rnd() % n + 1, c = rnd() % n + 1;
            } while (a == b || b == c || a == c);
            if (ask(a, b, c) <= (n - 4) / 6) { p1 = a, p2 = b; break; }
        }
        for (int i = 1; i <= n; i++) {
            V[i].clear();
        }
        for (int i = 1; i <= n; i++) if (i ^ p1 && i ^ p2) {
            int t = ask(p1, p2, i);
            mx = max(mx, t), V[t].push_back(i);
        }
        int x = V[mx--][0];
        if (V[mx].size() > 1 && ask(x, p1, V[mx][0]) > ask(x, p1, V[mx][1])) swap(V[mx][0], V[mx][1]);
        int y = V[mx][0];
        p[x] = 1, p[y] = 2;
        for (int i = 1; i <= n; i++) {
            if (i ^ x && i ^ y) p[i] = ask(x, y, i) + 2;
        }
        if (p[1] > p[2]) {
            for (int i = 1; i <= n; i++) p[i] = n - p[i] + 1;
        }
        cout << "!";
        for (int i = 1; i <= n; i++) {
            cout << " " << p[i];
        }
        cout << endl;
        int res; cin >> res;
    }
    return 0;
}