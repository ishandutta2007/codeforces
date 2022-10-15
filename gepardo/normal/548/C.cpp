#include <iostream>
#include <string>
#define int long long

using namespace std;

int used[2000000] = {};

int getCycle(int h, int a, int x, int y, int m)
{
    for (int i = 0; i < m; i++) used[i] = false;
    int c = 0;
    while (true)
    {
        if (used[h]) return -1;
        if (h == a) return c;
        used[h] = true;
        h = (h * x + y) % m;
        c++;
    }
}

int fullCycle(int h, int x, int y, int m)
{
    for (int i = 0; i < m; i++) used[i] = 0;
    int c = 0;
    while (true)
    {
        if (used[h] != 0) return c - used[h] + 1;
        used[h] = c + 1;
        h = (h * x + y) % m;
        c++;
    }
}

int preCycle(int h, int x, int y, int m)
{
    int pH = h;
    for (int i = 0; i < m; i++) used[i] = false;
    int c = 0;
    while (true)
    {
        if (used[h]) return c - fullCycle(pH, x, y, m);
        used[h] = true;
        h = (h * x + y) % m;
        c++;
    }
}

main()
{
    int m; cin >> m;
    int h1, a1; cin >> h1 >> a1;
    int x1, y1; cin >> x1 >> y1;
    int h2, a2; cin >> h2 >> a2;
    int x2, y2; cin >> x2 >> y2;
    int g1 = getCycle(h1, a1, x1, y1, m), g2 = getCycle(h2, a2, x2, y2, m);
    int p1 = preCycle(h1, x1, y1, m), p2 = preCycle(h2, x2, y2, m);
    int f1 = fullCycle(h1, x1, y1, m), f2 = fullCycle(h2, x2, y2, m);
    if (g1 < 0 || g2 < 0) {cout << -1; return 0;}
    if (g1 < p1 && g2 < p2)
    {
        if (g1 == g2) cout << g1; else cout << -1;
        return 0;
    }
    if (g2 < p2)
    {
        for (int t = g1; t <= g2; t += f1)
            if (t == g2) {cout << t; return 0;}
        cout << -1; return 0;
    }
    if (g1 < p1)
    {
        for (int t = g2; t <= g1; t += f2)
            if (t == g1) {cout << t; return 0;}
        cout << -1; return 0;
    }
    while (g1 < p2) g1 += f1;
    for (int t = g1; t < g1 + f1 * f2; t += f1)
        if ((t % f2) == (g2 % f2)) {cout << t; return 0;}
    cout << -1; return 0;
}