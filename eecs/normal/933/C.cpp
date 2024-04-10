#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<double, double> P;
int n, E, V, C, c1, c2, x[3], y[3], r[3], fa[3];
P S[100], T[100];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
bool comp(P x, P y) { return fabs(x.x - y.x) < 1e-10 ? x.y < y.y : x.x < y.x; }
bool operator == (P x, P y) { return fabs(x.x - y.x) + fabs(x.y - y.y) < 1e-10; }

bool chk1(int i, int j) {
    return hypot(x[i] - x[j], y[i] - y[j]) <= r[i] + r[j];
}

bool chk2(int i, int j) {
    return hypot(x[i] - x[j], y[i] - y[j]) >= abs(r[i] - r[j]);
}

void circle(int i, int j, P &p1, P &p2) {
    double ang = atan2(y[j] - y[i], x[j] - x[i]);
    double d = hypot(x[i] - x[j], y[i] - y[j]);
    double delta = acos((d * d + r[i] * r[i] - r[j] * r[j]) / (2 * r[i] * d));
    p1 = P(x[i] + r[i] * cos(ang + delta), y[i] + r[i] * sin(ang + delta));
    p2 = P(x[i] + r[i] * cos(ang - delta), y[i] + r[i] * sin(ang - delta));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &r[i]), fa[i] = i;
    }
    for (int i = 0; i < n; i++) {
        c2 = 0; P p1, p2;
        for (int j = 0; j < n; j++) if (i ^ j && chk1(i, j) && chk2(i, j)) {
            fa[find(i)] = find(j), circle(i, j, p1, p2);
            S[++c1] = T[++c2] = p1, S[++c1] = T[++c2] = p2;
        }
        sort(T + 1, T + c2 + 1, comp);
        for (int j = 1; j <= c2; j++) {
            if (j == 1 || !(T[j] == T[j - 1])) E++;
        }
    }
    sort(S + 1, S + c1 + 1, comp);
    for (int i = 1; i <= c1; i++) {
        if (i == 1 || !(S[i] == S[i - 1])) V++;
    }
    for (int i = 0; i < n; i++) {
        if (i == find(i)) C++;
    }
    printf("%d\n", E - V + C + 1);
    return 0;
}