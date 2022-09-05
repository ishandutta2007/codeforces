#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const double EPS = 1e-9;
int n, m;

struct point {
    double x, y;
    void read() { scanf("%lf %lf", &x, &y); }

    point operator + (const point &o) const { return (point){x + o.x, y + o.y}; }
    point operator - (const point &o) const { return (point){x - o.x, y - o.y}; }
    point operator * (const double &o) const { return (point){x * o, y * o}; }
    point operator / (const double &o) const { return (point){x / o, y / o}; }
    int operator * (const point &o) const { return x * o.x + y * o.y; }
    int operator ^ (const point &o) const { return x * o.y - y * o.x; }
    double len() { return sqrt(x * x + y * y); }
} P, Q, a[maxn], b[maxn];

int main() {
    P.read(), scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i].read(), a[i] = a[i] - P;
    Q.read(), scanf("%d", &m);
    for (int i = 1; i <= m; i++) b[i].read(), b[i] = b[i] - P;
    a[0] = a[n], b[0] = b[m];
    Q = Q - P, P = P - P;
    auto chk = [&](int i, int j) {
        double goal = Q.len(), l = 1e18, r = 0;
        vector<point> V;
        for (int p : {0, 1}) for (int q : {0, 1}) {
            V.push_back(Q - b[j - q] + a[i - p]);
            double len = V.back().len();
            l = min(l, len), r = max(r, len);
        }
        if (goal > r) return 0;
        if (goal >= l) return 1;
        for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) {
            if ((V[i] ^ V[j]) == 0) continue;
            double t = (P - V[i]) * (V[j] - V[i]) / (V[i] - V[j]).len();
            point ans = V[i] + (V[j] - V[i]) * (t / (V[i] - V[j]).len());
            if (ans.len() <= goal + EPS && (ans - V[i]).len() + (ans - V[j]).len() <= (V[i] - V[j]).len() + EPS) return 1;
        }
        return 0;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (chk(i, j)) puts("YES"), exit(0);
        }
    }
    puts("NO");
    return 0;
}